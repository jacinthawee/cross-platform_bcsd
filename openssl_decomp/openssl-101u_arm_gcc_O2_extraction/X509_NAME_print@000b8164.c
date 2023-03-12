
int X509_NAME_print(BIO *bp,X509_NAME *name,int obase)

{
  char *pcVar1;
  char *ptr;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *data;
  
  ptr = X509_NAME_oneline(name,(char *)0x0,0);
  if (ptr == (char *)0x0) {
    return 0;
  }
  pcVar4 = ptr + 1;
  pcVar1 = ptr;
  data = ptr + 1;
  if (*ptr == '\0') {
    CRYPTO_free(ptr);
    return 1;
  }
LAB_000b8188:
  do {
    pcVar5 = pcVar1;
    pcVar3 = pcVar4;
    pcVar1 = pcVar5 + 1;
    pcVar4 = pcVar3 + 1;
    if (*pcVar1 == '/') {
      if ((0x19 < (byte)pcVar5[2] - 0x41) ||
         (((byte)pcVar5[3] != 0x3d && ((0x19 < (byte)pcVar5[3] - 0x41 || (pcVar5[4] != '='))))))
      goto LAB_000b8188;
    }
    else if (*pcVar1 != '\0') goto LAB_000b8188;
    iVar2 = BIO_write(bp,data,(int)pcVar1 - (int)data);
    if (iVar2 != (int)pcVar1 - (int)data) {
LAB_000b81f8:
      iVar2 = 0;
      ERR_put_error(0xb,0x75,7,"t_x509.c",0x219);
      goto LAB_000b81b0;
    }
    if (*pcVar3 == '\0') goto LAB_000b81ae;
    iVar2 = BIO_write(bp,", ",2);
    if (iVar2 != 2) goto LAB_000b81f8;
    data = pcVar4;
    if (*pcVar3 == '\0') {
LAB_000b81ae:
      iVar2 = 1;
LAB_000b81b0:
      CRYPTO_free(ptr);
      return iVar2;
    }
  } while( true );
}

