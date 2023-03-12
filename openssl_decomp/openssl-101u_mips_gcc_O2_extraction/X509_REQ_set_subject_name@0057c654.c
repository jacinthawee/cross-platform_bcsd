
int X509_REQ_set_subject_name(X509_REQ *req,X509_NAME *name)

{
  int iVar1;
  
  if ((req != (X509_REQ *)0x0) && (req->req_info != (X509_REQ_INFO *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0057c670. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_X509_NAME_set_006a8f2c)(&req->req_info->subject);
    return iVar1;
  }
  return 0;
}

