
X509_REQ * d2i_X509_REQ_fp(FILE *fp,X509_REQ **req)

{
  X509_REQ *pXVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582480. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509_REQ *)(*(code *)PTR_ASN1_item_d2i_fp_006a8f98)(PTR_X509_REQ_it_006a8fac,fp,req);
  return pXVar1;
}

