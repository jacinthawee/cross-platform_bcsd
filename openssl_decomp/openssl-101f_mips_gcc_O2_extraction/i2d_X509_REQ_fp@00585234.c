
int i2d_X509_REQ_fp(FILE *fp,X509_REQ *req)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00585248. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_fp_006aa0b8)(PTR_X509_REQ_it_006aa0c4,fp,req);
  return iVar1;
}

