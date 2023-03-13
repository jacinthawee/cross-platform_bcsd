
X509 * d2i_X509_fp(FILE *fp,X509 **x509)

{
  X509 *pXVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582330. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509 *)(*(code *)PTR_ASN1_item_d2i_fp_006a8f98)(PTR_X509_it_006a8f9c,fp,x509);
  return pXVar1;
}

