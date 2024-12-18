#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include <string>
#include <map>
#include <memory>

namespace gstivr {

class CallSession;
class MediaSession;
class SessionManager
{
private:
    SessionManager();

public:
    static SessionManager* getInstance();

    std::shared_ptr<CallSession> getSession(std::string callID);
    std::shared_ptr<CallSession> createSession(std::string callID);
    std::shared_ptr<CallSession> findSession(std::shared_ptr<MediaSession> mediaSession);
    void removeSession(std::string callID);
    void removeSession(std::shared_ptr<CallSession>);
    void dumpSessions();

private:
    std::map<std::string, std::shared_ptr<CallSession>> _sessionMap;
};

} // namespace gstivr


#endif // SESSIONMANAGER_H
