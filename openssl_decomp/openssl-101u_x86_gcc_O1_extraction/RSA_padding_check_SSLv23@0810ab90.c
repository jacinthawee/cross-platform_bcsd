
int RSA_padding_check_SSLv23(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  uchar *puVar1;
  int iVar2;
  size_t __n;
  int iVar3;
  uchar *puVar4;
  int iVar5;
  
  if (fl < 10) {
    iVar3 = 0x70;
    iVar2 = 0x6f;
  }
  else {
    if (fl + 1 == rsa_len) {
      iVar2 = fl + -1;
      iVar3 = 0;
      puVar1 = f + 1;
      if (*f == '\x02') {
        do {
          puVar4 = puVar1;
          iVar5 = iVar3;
          if (*puVar4 == '\0') break;
          iVar3 = iVar3 + 1;
          puVar1 = puVar4 + 1;
          iVar5 = iVar2;
        } while (iVar3 != iVar2);
        if ((iVar2 == iVar5) || (iVar5 < 8)) {
          iVar3 = 0x80;
          iVar2 = 0x71;
        }
        else if (((((puVar4[-8] == '\x03') && (puVar4[-7] == '\x03')) && (puVar4[-6] == '\x03')) &&
                 ((puVar4[-5] == '\x03' && (puVar4[-4] == '\x03')))) &&
                ((puVar4[-3] == '\x03' && ((puVar4[-2] == '\x03' && (puVar4[-1] == '\x03')))))) {
          iVar3 = 0x88;
          iVar2 = 0x73;
        }
        else {
          __n = iVar2 - (iVar5 + 1);
          if ((int)__n <= tlen) {
            memcpy(to,puVar4 + 1,__n);
            return __n;
          }
          iVar3 = 0x8f;
          iVar2 = 0x6d;
        }
        goto LAB_0810ac34;
      }
    }
    iVar3 = 0x74;
    iVar2 = 0x6b;
  }
LAB_0810ac34:
  ERR_put_error(4,0x72,iVar2,"rsa_ssl.c",iVar3);
  return -1;
}

