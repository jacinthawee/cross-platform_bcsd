
int X509_REQ_get_attr_count(X509_REQ *req)

{
  int iVar1;
  
  iVar1 = X509at_get_attr_count((_STACK *)req->req_info->attributes);
  return iVar1;
}

