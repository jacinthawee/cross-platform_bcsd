
int PEM_get_EVP_CIPHER_INFO(char *header,EVP_CIPHER_INFO *cipher)

{
  uchar *puVar1;
  size_t __n;
  byte bVar2;
  EVP_CIPHER *pEVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  byte *local_20;
  
  cipher->cipher = (EVP_CIPHER *)0x0;
  if ((header != (char *)0x0) && (*header != '\n')) {
    bVar9 = false;
    bVar10 = *header == '\0';
    if (!bVar10) {
      iVar4 = 0xb;
      pbVar7 = (byte *)header;
      pbVar8 = (byte *)"Proc-Type: ";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar9 = *pbVar7 < *pbVar8;
        bVar10 = *pbVar7 == *pbVar8;
        pbVar7 = pbVar7 + 1;
        pbVar8 = pbVar8 + 1;
      } while (bVar10);
      if ((!bVar9 && !bVar10) != bVar9) {
        iVar11 = 500;
        iVar4 = 0x6b;
LAB_08155b9f:
        ERR_put_error(9,0x6b,iVar4,"pem_lib.c",iVar11);
        return 0;
      }
      if (header[0xb] == '4') {
        bVar9 = (byte)header[0xc] < 0x2c;
        bVar10 = header[0xc] == 0x2c;
        if (bVar10) {
          local_20 = (byte *)(header + 0xd);
          iVar4 = 9;
          pbVar7 = local_20;
          pbVar8 = (byte *)"ENCRYPTED";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar9 = *pbVar7 < *pbVar8;
            bVar10 = *pbVar7 == *pbVar8;
            pbVar7 = pbVar7 + 1;
            pbVar8 = pbVar8 + 1;
          } while (bVar10);
          if ((!bVar9 && !bVar10) == bVar9) {
            bVar2 = header[0xd];
            if ((bVar2 != 0) && (bVar2 != 10)) {
              do {
                local_20 = local_20 + 1;
                bVar2 = *local_20;
                if (bVar2 == 10) break;
              } while (bVar2 != 0);
            }
            bVar9 = false;
            bVar10 = bVar2 == 0;
            if (bVar10) {
              iVar11 = 0x1fd;
              iVar4 = 0x70;
            }
            else {
              iVar4 = 10;
              pbVar8 = (byte *)"DEK-Info: ";
              pbVar7 = local_20;
              do {
                pbVar7 = pbVar7 + 1;
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                bVar9 = *pbVar7 < *pbVar8;
                bVar10 = *pbVar7 == *pbVar8;
                pbVar8 = pbVar8 + 1;
              } while (bVar10);
              pbVar7 = local_20 + 0xb;
              if ((!bVar9 && !bVar10) == bVar9) {
                for (; ((bVar2 = *pbVar7, (byte)(bVar2 + 0xbf) < 0x1a || (bVar2 == 0x2d)) ||
                       ((byte)(bVar2 - 0x30) < 10)); pbVar7 = pbVar7 + 1) {
                }
                *pbVar7 = 0;
                pEVar3 = EVP_get_cipherbyname((char *)(local_20 + 0xb));
                cipher->cipher = pEVar3;
                *pbVar7 = bVar2;
                if (pEVar3 == (EVP_CIPHER *)0x0) {
                  ERR_put_error(9,0x6b,0x72,"pem_lib.c",0x219);
                  return 0;
                }
                __n = pEVar3->iv_len;
                if (0 < (int)__n) {
                  memset(cipher->iv,0,__n);
                }
                uVar6 = 0;
                if ((int)(__n * 2) < 1) {
                  return 1;
                }
                do {
                  bVar2 = pbVar7[uVar6 + 1];
                  iVar4 = (int)(char)bVar2;
                  if ((byte)(bVar2 - 0x30) < 10) {
                    iVar4 = iVar4 + -0x30;
                  }
                  else if ((byte)(bVar2 + 0xbf) < 6) {
                    iVar4 = iVar4 + -0x37;
                  }
                  else {
                    if (5 < (byte)(bVar2 + 0x9f)) {
                      ERR_put_error(9,0x65,0x67,"pem_lib.c",0x234);
                      return 0;
                    }
                    iVar4 = iVar4 + -0x57;
                  }
                  uVar5 = uVar6 & 1;
                  iVar11 = (int)uVar6 >> 1;
                  uVar6 = uVar6 + 1;
                  puVar1 = cipher->iv + iVar11;
                  *puVar1 = *puVar1 | (byte)(iVar4 << (-(uVar5 == 0) & 4U));
                } while (__n * 2 != uVar6);
                return 1;
              }
              iVar11 = 0x200;
              iVar4 = 0x69;
            }
            goto LAB_08155b9f;
          }
          ERR_put_error(9,0x6b,0x6a,"pem_lib.c",0x1f9);
        }
      }
      return 0;
    }
  }
  return 1;
}

