
int X509_REQ_add1_attr(X509_REQ *req,X509_ATTRIBUTE *attr)

{
  stack_st_X509_ATTRIBUTE *psVar1;
  
  psVar1 = X509at_add1_attr(&req->req_info->attributes,attr);
  return (uint)(psVar1 != (stack_st_X509_ATTRIBUTE *)0x0);
}
