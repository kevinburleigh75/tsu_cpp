#include <iostream>
#include <fstream>
#include <vector>
#include <functional>

using namespace std;

class Logger
{
public:
  virtual void log(string info) const = 0;
};

class ScreenLogger : public Logger
{
public:
  void log(string info) const
  {
    cout << info << endl;
  }
};

class FileLogger : public Logger
{
public:
  FileLogger (string filename)
    :_fstr(filename, ios::out | ios::app)
  { }

  void log(string info) const
  {
    _fstr << info << endl;
  }

  int getCount () const
  {
    return 10;
  }

private:
  mutable fstream _fstr;
};

class NoLogger : public Logger
{
public:
  void log (string info) const
  { }
};

class ScreenFileLogger : public Logger
{
public:
  ScreenFileLogger (string filename)
    :_fstr(filename, ios::out | ios::app)
  { }

  void log (string info) const
  {
    cout << info << endl;

    _fstr << info << endl;
  }

private:
  mutable fstream _fstr;
};

class MultiLogger : public Logger
{
public:
  void addLogger (Logger& logger)
  {
    _loggers.push_back(logger);
  }

  void log (string info) const
  {
    for (Logger& logger: _loggers) {
      logger.log(info);
    }
  }

private:
  std::vector<std::reference_wrapper<Logger>> _loggers;
};

class Worker
{
public:
  Worker (Logger& logger)
    : _logger(logger)
  { }

  void doWork ()
  {
    _logger.getCount();
    // complicated stuff
    _logger.log("the answer is ...");
  }

private:
  Logger& _logger;
};

void func(FileLogger& logger)
{
  logger.log("some stuff");
  logger.getCount();
}
int main ()
{
  // ScreenLogger logger;
  // FileLogger logger("out.txt");
  // NoLogger logger;
  // ScreenFileLogger logger("out.txt");

  ScreenLogger slogger;
  FileLogger flogger("out.txt");

  func(flogger);

  MultiLogger logger;
  logger.addLogger(slogger);
  logger.addLogger(flogger);

  Worker worker(logger);
  worker.doWork();
}

#if 0
#include <iostream>
#include <fstream>
#include <cmath>
#include <functional>
#include <vector>

class Logger
{
public:
  virtual void log (int xx, double yy) const = 0;
};

class FileLogger : public Logger
{
public:
  FileLogger (const std::string& filename)
    : Logger(),
      _fstr(filename, std::ios::out | std::ios::app)
  {
    if (!_fstr.is_open()) {
      std::cout << "failed to open file " << filename << std::endl;
      exit(1);
    }
  }

  virtual void log (int xx, double yy) const
  {
    _fstr << "The results were " << xx << " and " << yy << "!!" << std::endl;
  }

private:
  mutable std::fstream _fstr;
};

class ScreenLogger : public Logger
{
public:
  ScreenLogger ()
    : Logger()
  { }

  virtual void log (int xx, double yy) const
  {
    std::cout << "xx = " << xx << " and yy = " << yy << std::endl;
  }
};


class MultiLogger : public Logger
{
public:
  MultiLogger ()
    : Logger()
  { }

  void addLogger (Logger& logger)
  {
    _loggers.push_back(logger);
  }

  virtual void log (int xx, double yy) const
  {
    for (Logger& logger : _loggers) {
      logger.log(xx, yy);
    }
  }

private:
  std::vector<std::reference_wrapper<Logger>> _loggers;
};

class Worker
{
public:
  Worker (Logger& logger)
    : _logger(logger),
      _counter(0)
  { }

  void doWork ()
  {
    _counter++;
    _logger.log(_counter, sqrt(_counter));
  }

private:
  Logger& _logger;
  int     _counter;
};

int main ()
{
  // FileLogger   fileLogger("out.txt");
  // ScreenLogger screenLogger;
  // MultiLogger logger;
  // logger.addLogger(fileLogger);
  // logger.addLogger(screenLogger);

  // FileLogger   logger("out.txt");
  // ScreenLogger logger;

  Worker worker(logger);

  for (int ii=0; ii<10; ii++) {
    worker.doWork();
  }
}
#endif
