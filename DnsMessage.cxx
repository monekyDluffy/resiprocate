#include "util/DataStream.hxx"
#include "util/Socket.hxx"
#include "util/Data.hxx"
#include "sipstack/DnsMessage.hxx"

using namespace Vocal2;

Data 
DnsMessage::brief() const 
{ 
   Data result;
   DataStream strm(result);
   strm << "DnsMessage: tid=" << mTransactionId << mIsComplete ? " complete" : " partial";
   strm.flush();
   return result;
}

std::ostream& 
DnsMessage::encode(std::ostream& strm) const
{
   strm << "Dns: tid=" << mTransactionId << (mIsComplete ? " complete " : " partial ");
   for (DnsResolver::TupleIterator i=mStart; i!=mEnd; i++)
   {
      strm << *i << ",";
   }
   return strm;
}
