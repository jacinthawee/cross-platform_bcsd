
int PEM_get_EVP_CIPHER_INFO(char *header,EVP_CIPHER_INFO *cipher)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  EVP_CIPHER *pEVar6;
  uint uVar7;
  undefined4 uVar8;
  uchar *puVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  char *pcVar13;
  
  cipher->cipher = (EVP_CIPHER *)0x0;
  if (((header == (char *)0x0) || (*header == '\0')) || (*header == '\n')) {
LAB_0056b664:
    iVar3 = 1;
  }
  else {
    iVar3 = (*(code *)PTR_strncmp_006a9970)(header,"Proc-Type: ",0xb);
    if (iVar3 != 0) {
      uVar12 = 0x6b;
      uVar8 = 0x1ee;
LAB_0056b69c:
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x6b,uVar12,"pem_lib.c",uVar8);
      return 0;
    }
    if (header[0xb] != '4') {
      return 0;
    }
    if (header[0xc] != ',') {
      return 0;
    }
    pcVar13 = header + 0xd;
    iVar4 = (*(code *)PTR_strncmp_006a9970)(pcVar13,"ENCRYPTED",9);
    if (iVar4 == 0) {
      cVar1 = header[0xd];
      while (cVar1 != '\n') {
        if (cVar1 == '\0') {
          uVar12 = 0x70;
          uVar8 = 0x1fe;
          goto LAB_0056b69c;
        }
        pcVar13 = pcVar13 + 1;
        cVar1 = *pcVar13;
      }
      iVar3 = (*(code *)PTR_strncmp_006a9970)(pcVar13 + 1,"DEK-Info: ",10);
      puVar2 = PTR_EVP_get_cipherbyname_006a7394;
      if (iVar3 != 0) {
        uVar12 = 0x69;
        uVar8 = 0x203;
        goto LAB_0056b69c;
      }
      pcVar13 = pcVar13 + 0xb;
      while( true ) {
        cVar1 = *pcVar13;
        uVar5 = (int)cVar1 & 0xff;
        if (((0x19 < uVar5 - 0x41) && ((int)cVar1 != 0x2d)) && (9 < uVar5 - 0x30)) break;
        pcVar13 = pcVar13 + 1;
      }
      *pcVar13 = '\0';
      pEVar6 = (EVP_CIPHER *)(*(code *)puVar2)();
      cipher->cipher = pEVar6;
      *pcVar13 = cVar1;
      if (pEVar6 != (EVP_CIPHER *)0x0) {
        iVar3 = pEVar6->iv_len;
        if (0 < iVar3) {
          (*(code *)PTR_memset_006a99f4)(cipher->iv,0,iVar3);
        }
        uVar5 = 0;
        if (0 < iVar3 << 1) {
          do {
            pcVar13 = pcVar13 + 1;
            uVar7 = (uint)*pcVar13;
            uVar10 = uVar7 & 0xff;
            if (uVar10 - 0x30 < 10) {
              iVar4 = uVar7 - 0x30;
            }
            else if (uVar10 - 0x41 < 6) {
              iVar4 = uVar7 - 0x37;
            }
            else {
              iVar4 = uVar7 - 0x57;
              if (5 < uVar10 - 0x61) {
                (*(code *)PTR_ERR_put_error_006a7f34)(9,0x65,0x67,"pem_lib.c",0x235);
                return 0;
              }
            }
            iVar11 = 4;
            if ((uVar5 & 1) != 0) {
              iVar11 = 0;
            }
            puVar9 = cipher->iv + ((int)uVar5 >> 1);
            uVar5 = uVar5 + 1;
            *puVar9 = *puVar9 | (byte)(iVar4 << iVar11);
          } while (iVar3 << 1 != uVar5);
        }
        goto LAB_0056b664;
      }
      uVar12 = 0x72;
      uVar8 = 0x21b;
    }
    else {
      uVar12 = 0x6a;
      uVar8 = 0x1f9;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(9,0x6b,uVar12,"pem_lib.c",uVar8);
  }
  return iVar3;
}

