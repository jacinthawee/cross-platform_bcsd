
int X509_REQ_add1_attr_by_txt(X509_REQ *req,char *attrname,int type,uchar *bytes,int len)

{
  stack_st_X509_ATTRIBUTE *psVar1;
  
  psVar1 = X509at_add1_attr_by_txt(&req->req_info->attributes,attrname,type,bytes,len);
  return (uint)(psVar1 != (stack_st_X509_ATTRIBUTE *)0x0);
}

