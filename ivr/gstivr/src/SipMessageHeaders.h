#ifndef SIP_MESSAGE_HEADERS_H
#define SIP_MESSAGE_HEADERS_H

namespace gstivr {

class SipMessageHeaders
{
public:
	SipMessageHeaders() = delete;

	static constexpr auto VIA            = "Via";
	static constexpr auto FROM           = "From";
	static constexpr auto TO             = "To";
	static constexpr auto CALL_ID        = "Call-ID";
	static constexpr auto CSEQ           = "CSeq";
	static constexpr auto CONTACT        = "Contact";
	static constexpr auto CONTENT_LENGTH = "Content-Length";
	static constexpr auto CONTENT_TYPE 	 = "Content-Type";
	static constexpr auto REFER_TO       = "Refer-To";
	static constexpr auto REFERED_BY     = "Referred-By";

	static constexpr auto HEADERS_DELIMETER = "\r\n";
};

} // namespace gstivr


#endif
