
X509_SIG * d2i_PKCS8_fp(FILE *fp,X509_SIG **p8)

{
  X509_SIG *pXVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00585794. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509_SIG *)
           (*(code *)PTR_ASN1_d2i_fp_006aa0d0)
                     (PTR_X509_SIG_new_006aa0e4,PTR_d2i_X509_SIG_006a985c,fp,p8);
  return pXVar1;
}

