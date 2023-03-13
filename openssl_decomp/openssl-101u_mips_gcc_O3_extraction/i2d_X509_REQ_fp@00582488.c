
int i2d_X509_REQ_fp(FILE *fp,X509_REQ *req)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0058249c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_fp_006a8fa0)(PTR_X509_REQ_it_006a8fac,fp,req);
  return iVar1;
}

