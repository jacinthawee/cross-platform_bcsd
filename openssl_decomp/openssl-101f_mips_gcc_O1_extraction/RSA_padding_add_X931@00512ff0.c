
int RSA_padding_add_X931(uchar *to,int tlen,uchar *f,int fl)

{
  int iVar1;
  int iVar2;
  uchar *puVar3;
  uchar *puVar4;
  
  iVar2 = tlen - fl;
  if (iVar2 + -2 < 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x7f,0x6e,"rsa_x931.c",0x50);
    iVar2 = -1;
  }
  else {
    if (iVar2 == 2) {
      puVar3 = to + 1;
      *to = 'j';
    }
    else {
      puVar3 = to + 1;
      *to = 'k';
      puVar4 = puVar3;
      if (iVar2 + -2 != 1) {
        puVar4 = puVar3 + iVar2 + -3;
        (*(code *)PTR_memset_006aab00)(puVar3,0xbb);
      }
      puVar3 = puVar4 + 1;
      *puVar4 = 0xba;
    }
    iVar1 = (*(code *)PTR_memcpy_006aabf4)(puVar3,f,fl);
    iVar2 = 1;
    *(undefined *)(iVar1 + fl) = 0xcc;
  }
  return iVar2;
}

