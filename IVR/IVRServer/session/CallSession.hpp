#ifndef CALLSESSION_H
#define CALLSESSION_H

#include <memory>

#include "SipClient.hpp"

class CallSession
{
public:

	enum class State
	{
		Invited,
		Busy,
		Unavailable,
		Cancel,
		Bye,
		Connected,
	};


    explicit CallSession(std::string callID);

	void setState(State state);
	void setDest(std::shared_ptr<SipClient> dest, uint32_t destRtpPort);

	std::string getCallID() const;
	std::shared_ptr<SipClient> getSrc() const;
	std::shared_ptr<SipClient> getDest() const;
	uint32_t getSrcRtpPort() const;
	uint32_t getDestRtpPort() const;
	State getState() const;
    std::string getFromTag() const;
    void setFromTag(std::string fromTag);
    std::string getToTag() const;
    void setToTag(std::string toTag);

    std::string toString();
private:
	std::string _callID;
	std::shared_ptr<SipClient> _src;
	std::shared_ptr<SipClient> _dest;
	State _state;

	uint32_t _srcRtpPort;
	uint32_t _destRtpPort;

    std::string _fromTag;
    std::string _toTag;
};

#endif