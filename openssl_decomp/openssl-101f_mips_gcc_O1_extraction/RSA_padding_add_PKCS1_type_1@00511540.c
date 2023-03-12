
int RSA_padding_add_PKCS1_type_1(uchar *to,int tlen,uchar *f,int fl)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = PTR_memset_006aab00;
  if (fl < tlen + -10) {
    *to = '\0';
    iVar3 = (tlen + -3) - fl;
    to[1] = '\x01';
    iVar2 = (*(code *)puVar1)(to + 2,0xff,iVar3);
    *(undefined *)(iVar2 + iVar3) = 0;
    (*(code *)PTR_memcpy_006aabf4)(iVar2 + iVar3 + 1,f,fl);
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(4,0x6c,0x6e,"rsa_pk1.c",0x49);
  return 0;
}

