
char * SSL_get_shared_ciphers(SSL *s,char *buf,int len)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  
  if (s->session == (SSL_SESSION *)0x0) {
    return (char *)0x0;
  }
  iVar6 = *(int *)(s->session->krb5_client_princ + 0x2c);
  pcVar5 = (char *)0x0;
  if (iVar6 != 0) {
    if (len < 2) {
      pcVar5 = (char *)0x0;
    }
    else {
      iVar4 = 0;
      pcVar5 = buf;
      while( true ) {
        iVar1 = (*(code *)PTR_sk_num_006a7f2c)(iVar6);
        if (iVar1 <= iVar4) break;
        iVar1 = (*(code *)PTR_sk_value_006a7f24)(iVar6,iVar4);
        uVar2 = *(undefined4 *)(iVar1 + 4);
        iVar1 = (*(code *)PTR_strlen_006aab30)(uVar2);
        if (len <= iVar1) {
          if (pcVar5 == buf) {
            *buf = '\0';
          }
          else {
            pcVar5[-1] = '\0';
          }
          return buf;
        }
        (*(code *)PTR_memcpy_006aabf4)(pcVar5,uVar2,iVar1);
        pcVar3 = pcVar5 + iVar1;
        len = len - (iVar1 + 1);
        pcVar5 = pcVar5 + iVar1 + 1;
        *pcVar3 = ':';
        iVar4 = iVar4 + 1;
      }
      pcVar5[-1] = '\0';
      pcVar5 = buf;
    }
  }
  return pcVar5;
}

