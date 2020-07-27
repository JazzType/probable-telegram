#include <cstdint>
#include <string>
#include <unordered_map>
#include "constants.h"

Mapping::Mapping() {
  std::unordered_map<std::uint8_t, std::string> submap;
  // Code Page 0
  submap[0x05] = "Sync";
  submap[0x06] = "Responses";
  submap[0x07] = "Add";
  submap[0x08] = "Change";
  submap[0x09] = "Delete";
  submap[0x0A] = "Fetch";
  submap[0x0B] = "SyncKey";
  submap[0x0C] = "ClientId";
  submap[0x0D] = "ServerId";
  submap[0x0E] = "Status";
  submap[0x0F] = "Collection";
  submap[0x10] = "Class";
  submap[0x12] = "CollectionId";
  submap[0x13] = "GetChanges";
  submap[0x14] = "MoreAvailable";
  submap[0x15] = "WindowSize";
  submap[0x16] = "Commands";
  submap[0x17] = "Options";
  submap[0x18] = "FilterType";
  submap[0x19] = "Truncation";
  submap[0x1B] = "Conflict";
  submap[0x1C] = "Collections";
  submap[0x1D] = "ApplicationData";
  submap[0x1E] = "DeletesAsMoves";
  submap[0x20] = "Supported";
  submap[0x21] = "SoftDelete";
  submap[0x22] = "MIMESupport";
  submap[0x23] = "MIMETruncation";
  submap[0x24] = "Wait";
  submap[0x25] = "Limit";
  submap[0x26] = "Partial";
  submap[0x27] = "ConversationMode";
  submap[0x28] = "MaxItems";
  submap[0x29] = "HeartbeatInterval";

  // Code page 1
  submap[0x05] = "Anniversary";
  submap[0x06] = "AssistantName";
  submap[0x07] = "AssistantPhoneNumber";
  submap[0x08] = "Birthday";
  submap[0x08] = "Birthday";
  submap[0x09] = "Body";
  submap[0x0A] = "BodySize";
  submap[0x0B] = "BodyTruncated";
  submap[0x0C] = "Business2PhoneNumber";
  submap[0x0D] = "BusinessAddressCity";
  submap[0x0E] = "BusinessAddressCountry";
  submap[0x0F] = "BusinessAddressPostalCode";
  submap[0x10] = "BusinessAddressState";
  submap[0x11] = "BusinessAddressStreet";
  submap[0x12] = "BusinessFaxNumber";
  submap[0x13] = "BusinessPhoneNumber";
  submap[0x14] = "CarPhoneNumber";
  submap[0x15] = "Categories";
  submap[0x16] = "Category";
  submap[0x17] = "Children";
  submap[0x18] = "Child";
  submap[0x19] = "CompanyName";
  submap[0x1A] = "Department";
  submap[0x1B] = "Email1Address";
  submap[0x1C] = "Email2Address";
  submap[0x1D] = "Email3Address";
  submap[0x1E] = "FileAs";
  submap[0x1F] = "FirstName";
  submap[0x20] = "Home2PhoneNumber";
  submap[0x21] = "HomeAddressCity";
  submap[0x22] = "HomeAddressCountry";
  submap[0x23] = "HomeAddressPostalCode";
  submap[0x24] = "HomeAddressState";
  submap[0x25] = "HomeAddressStreet";
  submap[0x26] = "HomeFaxNumber";
  submap[0x27] = "HomePhoneNumber";
  submap[0x28] = "JobTitle";
  submap[0x29] = "LastName";
  submap[0x2A] = "MiddleName";
  submap[0x2B] = "MobilePhoneNumber";
  submap[0x2C] = "OfficeLocation";
  submap[0x2D] = "OtherAddressCity";
  submap[0x2E] = "OtherAddressCountry";
  submap[0x2F] = "OtherAddressPostalCode";
  submap[0x30] = "OtherAddressState";
  submap[0x31] = "OtherAddressStreet";
  submap[0x32] = "PagerNumber";
  submap[0x33] = "RadioPhoneNumber";
  submap[0x34] = "Spouse";
  submap[0x35] = "Suffix";
  submap[0x36] = "Title";
  submap[0x37] = "WebPage";
  submap[0x38] = "YomiCompanyName";
  submap[0x39] = "YomiFirstName";
  submap[0x3A] = "YomiLastName";
  submap[0x3C] = "Picture";
  submap[0x3D] = "Alias";
  submap[0x3E] = "WeightedRank";

  // Code Page 2
}