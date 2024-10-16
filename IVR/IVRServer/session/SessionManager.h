#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include <string>
#include <map>
#include <memory>

class CallSession;
class MediaSession;
class SessionManager
{
private:
    SessionManager();

public:
    static SessionManager* getInstance();

    std::shared_ptr<CallSession> createSession(std::string callerNumber, std::string callID);
    void removeSession(std::string callID);
    void dumpSessions();

private:
    std::map<std::string, std::shared_ptr<CallSession>> _sessionMap;
};

#endif // SESSIONMANAGER_H
