
int X509_set_subject_name(X509 *x,X509_NAME *name)

{
  int iVar1;
  
  if ((x != (X509 *)0x0) && (x->cert_info != (X509_CINF *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0057c160. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_X509_NAME_set_006a8f2c)(&x->cert_info->subject);
    return iVar1;
  }
  return 0;
}

