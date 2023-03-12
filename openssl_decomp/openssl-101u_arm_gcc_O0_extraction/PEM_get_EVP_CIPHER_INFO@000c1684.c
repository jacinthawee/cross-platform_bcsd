
int PEM_get_EVP_CIPHER_INFO(char *header,EVP_CIPHER_INFO *cipher)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  EVP_CIPHER *pEVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  char cVar8;
  uint uVar9;
  char *__s1;
  size_t __n;
  int iVar10;
  uchar *__s;
  bool bVar11;
  
  cipher->cipher = (EVP_CIPHER *)0x0;
  if (((header != (char *)0x0) && (*header != '\0')) && (*header != '\n')) {
    iVar3 = strncmp(header,"Proc-Type: ",0xb);
    if (iVar3 != 0) {
      ERR_put_error(9,0x6b,0x6b,"pem_lib.c",0x1ee);
      return 0;
    }
    if (header[0xb] != '4') {
      return 0;
    }
    if (header[0xc] != ',') {
      return 0;
    }
    __s1 = header + 0xd;
    iVar3 = strncmp(__s1,"ENCRYPTED",9);
    if (iVar3 != 0) {
      ERR_put_error(9,0x6b,0x6a,"pem_lib.c",0x1f9);
      return 0;
    }
    cVar8 = header[0xd];
    if (cVar8 != '\0' && cVar8 != '\n') {
      do {
        __s1 = __s1 + 1;
        cVar8 = *__s1;
      } while (cVar8 != '\0' && cVar8 != '\n');
    }
    if (cVar8 == '\0') {
      ERR_put_error(9,0x6b,0x70,"pem_lib.c",0x1fe);
      return 0;
    }
    iVar3 = strncmp(__s1 + 1,"DEK-Info: ",10);
    pbVar2 = (byte *)(__s1 + 0xb);
    if (iVar3 != 0) {
      ERR_put_error(9,0x6b,0x69,"pem_lib.c",0x203);
      return 0;
    }
    do {
      pbVar7 = pbVar2;
      bVar1 = *pbVar7;
      uVar9 = (uint)bVar1;
      bVar11 = 0x2c < uVar9;
      if (uVar9 != 0x2d) {
        bVar11 = 0x18 < uVar9 - 0x41;
      }
      pbVar2 = pbVar7 + 1;
    } while ((!bVar11 || (uVar9 == 0x2d || uVar9 - 0x41 == 0x19)) || (uVar9 - 0x30 < 10));
    *pbVar7 = 0;
    pEVar4 = EVP_get_cipherbyname(__s1 + 0xb);
    cipher->cipher = pEVar4;
    *pbVar7 = bVar1;
    if (pEVar4 == (EVP_CIPHER *)0x0) {
      ERR_put_error(9,0x6b,0x72,"pem_lib.c",0x21b);
      return 0;
    }
    __n = pEVar4->iv_len;
    __s = cipher->iv;
    if (0 < (int)__n) {
      memset(__s,0,__n);
    }
    if (0 < (int)(__n * 2)) {
      uVar9 = 0;
      do {
        uVar6 = (uint)pbVar7[uVar9 + 1];
        uVar5 = uVar6 - 0x30;
        if (9 < (uVar5 & 0xff)) {
          uVar5 = uVar6 - 0x37;
          if ((5 < uVar6 - 0x41) && (uVar5 = uVar6 - 0x57, 5 < uVar6 - 0x61)) {
            ERR_put_error(9,0x65,0x67,"pem_lib.c",0x235);
            return 0;
          }
        }
        uVar6 = uVar9 & 1;
        iVar3 = (int)uVar9 >> 1;
        uVar9 = uVar9 + 1;
        if (uVar6 == 0) {
          iVar10 = 4;
        }
        else {
          iVar10 = 0;
        }
        __s[iVar3] = (byte)(uVar5 << iVar10) | __s[iVar3];
      } while (uVar9 != __n * 2);
    }
  }
  return 1;
}

