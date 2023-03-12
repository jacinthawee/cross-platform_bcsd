
int RSA_padding_check_none(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  if (tlen < fl) {
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x6f,0x6d,"rsa_none.c",0x57);
    tlen = -1;
  }
  else {
    (*(code *)PTR_memset_006a99f4)(to,0,tlen - fl);
    (*(code *)PTR_memcpy_006a9aec)(to + (tlen - fl),f,fl);
  }
  return tlen;
}

