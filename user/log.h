#ifndef USER_LOG_H
#define USER_LOG_H

enum user_log_level {
        USER_LOG_FATAL      = 0,
        USER_LOG_ERROR      = 1,
        USER_LOG_WARRNING   = 2,
        USER_LOG_INFO       = 3,
        USER_LOG_DEBUG      = 4,
        USER_LOG_VERBOSE    = 5,
};

#define DEFAULT_USER_LOG_LEVEL USER_LOG_DEBUG

#ifndef LOG_LEVEL
#define LOG_LEVEL 1
#endif


#define log_fl(fmt, ...) printf("%s %s[%d]: " fmt, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)

#define loge(fmt, ...) \
    if (LOG_LEVEL >= USER_LOG_ERROR){\
        log_fl(fmt, ##__VA_ARGS__);}

#define logw(fmt, ...) \
    if (LOG_LEVEL >= USER_LOG_WARRNING){\
        log_fl(fmt, ##__VA_ARGS__);}

#define logi(fmt, ...) \
    if (LOG_LEVEL >= USER_LOG_INFO){\
        log_fl(fmt, ##__VA_ARGS__);}

#define logd(fmt, ...) \
    if (LOG_LEVEL >= USER_LOG_DEBUG){\
        log_fl(fmt, ##__VA_ARGS__);}

#define logv(fmt, ...) \
    if (LOG_LEVEL >= USER_LOG_VERBOSE){\
        log_fl(fmt, ##__VA_ARGS__);}

#endif //end of USER_LOG_H