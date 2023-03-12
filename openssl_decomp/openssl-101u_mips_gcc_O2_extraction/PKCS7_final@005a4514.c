
int PKCS7_final(PKCS7 *p7,BIO *data,int flags)

{
  BIO *bio;
  int iVar1;
  
  bio = PKCS7_dataInit(p7,(BIO *)0x0);
  if (bio == (BIO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x86,0x41,"pk7_smime.c",0x75);
    return 0;
  }
  (*(code *)PTR_SMIME_crlf_copy_006a9170)(data,bio,flags);
  (*(code *)PTR_BIO_ctrl_006a6e18)(bio,0xb,0,0);
  iVar1 = PKCS7_dataFinal(p7,bio);
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x86,0x91,"pk7_smime.c",0x7e);
  }
  (*(code *)PTR_BIO_free_all_006a6e74)(bio);
  return (uint)(iVar1 != 0);
}

