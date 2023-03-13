
char * SSL_get_shared_ciphers(SSL *s,char *buf,int len)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  
  if (s->session == (SSL_SESSION *)0x0) {
    return (char *)0x0;
  }
  iVar6 = *(int *)(s->session->krb5_client_princ + 0x2c);
  if ((iVar6 != 0) && (1 < len)) {
    iVar1 = (*(code *)PTR_sk_num_006a6e2c)(iVar6);
    if (iVar1 != 0) {
      iVar1 = 0;
      pcVar5 = buf;
      while( true ) {
        iVar2 = (*(code *)PTR_sk_num_006a6e2c)(iVar6);
        if (iVar2 <= iVar1) {
          pcVar5[-1] = '\0';
          return buf;
        }
        iVar2 = (*(code *)PTR_sk_value_006a6e24)(iVar6,iVar1);
        uVar3 = *(undefined4 *)(iVar2 + 4);
        iVar2 = (*(code *)PTR_strlen_006a9a24)(uVar3);
        if (len <= iVar2) break;
        (*(code *)PTR_memcpy_006a9aec)(pcVar5,uVar3,iVar2);
        pcVar4 = pcVar5 + iVar2;
        len = len - (iVar2 + 1);
        pcVar5 = pcVar5 + iVar2 + 1;
        *pcVar4 = ':';
        iVar1 = iVar1 + 1;
      }
      if (pcVar5 == buf) {
        *buf = '\0';
      }
      else {
        pcVar5[-1] = '\0';
      }
      return buf;
    }
  }
  return (char *)0x0;
}

