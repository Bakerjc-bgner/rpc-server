#ifndef ROCKET_COMMON_LOG_H
#define ROCKET_COMMON_LOG_H
#include <string>
namespace rocket {
// 日志模块
//  log level
enum class LogLevel {
    LOG_LEVEL_DEBUG = 1,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_FATAL,
    LOG_LEVEL_NUM
};
template <typename... Args>
std::string formatString(const char* str, Args&&... args) {
    int size =
        snprintf(nullptr, 0, str,
                 args...);  // 计算格式化后的长度,缓冲区大小预估。不实际写入

    std::string result;  // 返回值
    if (size > 0) {
        result.resize(size);                           // 分配空间
        snprintf(&result[0], size + 1, str, args...);  // 格式化
    }
    return result;
}

// log module
class logEvent {
   public:
    logEvent();
    ~logEvent();
    std::string getFileName() const { return m_fileName; }
    std::string getContent() const { return m_content; }
    int getPid() const { return m_pid; }
    LogLevel getLogLevel();
    void printLog();

   private:
    std::string m_fileName;  // 文件名
    std::string m_content;   // 日志内容
    int32_t m_file_line;     // 文件行号
    int32_t m_pid;           // 进程id
    int32_t m_tid;           // 线程id
    LogLevel m_logLevel;     // 日志级别
};

}  // namespace rocket

#endif