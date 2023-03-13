
int RSA_padding_add_none(uchar *to,int tlen,uchar *f,int fl)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (tlen < fl) {
    uVar2 = 0x6e;
    uVar1 = 0x45;
  }
  else {
    if (tlen <= fl) {
      (*(code *)PTR_memcpy_006a9aec)(to,f,fl);
      return 1;
    }
    uVar2 = 0x7a;
    uVar1 = 0x4a;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(4,0x6b,uVar2,"rsa_none.c",uVar1);
  return 0;
}

