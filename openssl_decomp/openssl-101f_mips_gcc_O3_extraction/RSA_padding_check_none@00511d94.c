
int RSA_padding_check_none(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  if (tlen < fl) {
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x6f,0x6d,"rsa_none.c",0x5a);
    tlen = -1;
  }
  else {
    (*(code *)PTR_memset_006aab00)(to,0,tlen - fl);
    (*(code *)PTR_memcpy_006aabf4)(to + (tlen - fl),f,fl);
  }
  return tlen;
}

