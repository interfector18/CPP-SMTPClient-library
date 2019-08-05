#ifndef MESSAGE_H
#define MESSAGE_H

#include <cstring>
#include "MessageAddress.h"
#include "Attachment.h"
#include <vector>

#ifdef _WIN32
	#ifdef SMTPCLIENT_EXPORTS  
		#define MESSAGE_API __declspec(dllexport)   
	#else  
		#define MESSAGE_API __declspec(dllimport)   
	#endif
#else
	#define MESSAGE_API
#endif

namespace jed_utils
{
	class MESSAGE_API Message
	{
	public:
		Message(const MessageAddress &pFrom,
			const MessageAddress &pTo,
			const std::string &pSubject,
			const std::string &pBody,
			const std::vector<MessageAddress> &pCc = std::vector<MessageAddress>(),
			const std::vector<MessageAddress> &pBcc = std::vector<MessageAddress>(),
			const std::vector<Attachment> &pAttachments = std::vector<Attachment>());
		Message(const MessageAddress &pFrom,
			const std::vector<MessageAddress> &pTo,
			const std::string &pSubject,
			const std::string &pBody,
			const std::vector<MessageAddress> &pCc = std::vector<MessageAddress>(),
			const std::vector<MessageAddress> &pBcc = std::vector<MessageAddress>(),
			const std::vector<Attachment> &pAttachments = std::vector<Attachment>());
		Message(const Message &);
		~Message();
		Message &operator=(const Message &msg);
		virtual const std::string getMimeType() const = 0;
		const MessageAddress getFrom() const;
		const std::vector<MessageAddress> &getTo() const;
		size_t getToCount() const;
		const std::string &getSubject() const;
		const std::string &getBody() const;
		const std::vector<MessageAddress> &getCc() const;
		size_t getCcCount() const;
		const std::vector<MessageAddress> &getBcc() const;
		size_t getBccCount() const;
		const std::vector<Attachment> &getAttachments() const;
		size_t getAttachmentsCount() const;
	protected:
		MessageAddress mFrom;
		std::vector<MessageAddress> *mTo = nullptr;
		std::vector<MessageAddress> *mCc = nullptr;
		std::vector<MessageAddress> *mBcc = nullptr;
		std::string *mSubject = nullptr;
		std::string *mBody = nullptr;
		std::vector<Attachment> *mAttachments = nullptr;
	};
}

#endif
