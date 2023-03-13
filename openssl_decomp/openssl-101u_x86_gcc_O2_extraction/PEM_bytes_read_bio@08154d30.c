
int PEM_bytes_read_bio(uchar **pdata,long *plen,char **pnm,char *name,BIO *bp,undefined1 *cb,void *u
                      )

{
  int iVar1;
  size_t sVar2;
  ulong uVar3;
  EVP_PKEY_ASN1_METHOD *pEVar4;
  byte *__s;
  byte *pbVar5;
  char *pcVar6;
  byte *pbVar7;
  byte *pbVar8;
  char *pcVar9;
  int in_GS_OFFSET;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  byte bVar13;
  byte *local_48;
  char *local_44;
  uchar *local_40;
  long local_3c;
  ENGINE *local_38;
  EVP_CIPHER_INFO local_34;
  int local_20;
  
  bVar13 = 0;
  local_48 = (byte *)0x0;
  local_44 = (char *)0x0;
  local_40 = (uchar *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  do {
    iVar1 = PEM_read_bio(bp,(char **)&local_48,&local_44,&local_40,&local_3c);
    __s = local_48;
    if (iVar1 == 0) {
      uVar3 = ERR_peek_error();
      if ((uVar3 & 0xfff) == 0x6c) {
        ERR_add_error_data(2,"Expecting: ",name);
      }
LAB_08154f11:
      if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return iVar1;
    }
    iVar1 = strcmp((char *)local_48,name);
    bVar10 = false;
    bVar11 = iVar1 == 0;
    if (bVar11) {
LAB_08154ed0:
      iVar1 = PEM_get_EVP_CIPHER_INFO(local_44,&local_34);
      if ((iVar1 == 0) || (iVar1 = PEM_do_header(&local_34,local_40,&local_3c,cb,u), iVar1 == 0)) {
        iVar1 = 0;
        CRYPTO_free(local_48);
        CRYPTO_free(local_44);
        CRYPTO_free(local_40);
      }
      else {
        *pdata = local_40;
        *plen = local_3c;
        if (pnm == (char **)0x0) {
          iVar1 = 1;
          CRYPTO_free(local_48);
          CRYPTO_free(local_44);
        }
        else {
          iVar1 = 1;
          *pnm = (char *)local_48;
          CRYPTO_free(local_44);
        }
      }
      goto LAB_08154f11;
    }
    iVar1 = 0x10;
    pbVar7 = (byte *)name;
    pbVar5 = (byte *)"ANY PRIVATE KEY";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar10 = *pbVar7 < *pbVar5;
      bVar11 = *pbVar7 == *pbVar5;
      pbVar7 = pbVar7 + (uint)bVar13 * -2 + 1;
      pbVar5 = pbVar5 + (uint)bVar13 * -2 + 1;
    } while (bVar11);
    if (bVar11) {
      iVar1 = 0x16;
      pbVar7 = __s;
      pbVar5 = (byte *)"ENCRYPTED PRIVATE KEY";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar11 = *pbVar7 == *pbVar5;
        pbVar7 = pbVar7 + (uint)bVar13 * -2 + 1;
        pbVar5 = pbVar5 + (uint)bVar13 * -2 + 1;
      } while (bVar11);
      if (!bVar11) {
        iVar1 = 0xc;
        pbVar7 = __s;
        pbVar5 = (byte *)0x822a6b5;
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar11 = *pbVar7 == *pbVar5;
          pbVar7 = pbVar7 + (uint)bVar13 * -2 + 1;
          pbVar5 = pbVar5 + (uint)bVar13 * -2 + 1;
        } while (bVar11);
        if (!bVar11) {
          sVar2 = strlen((char *)__s);
          bVar10 = sVar2 == 0xc;
          if (0xc < (int)sVar2) {
            pbVar7 = __s + (sVar2 - 0xb);
            iVar1 = 0xc;
            pbVar5 = pbVar7;
            pbVar8 = (byte *)0x822a6b5;
            do {
              if (iVar1 == 0) break;
              iVar1 = iVar1 + -1;
              bVar10 = *pbVar5 == *pbVar8;
              pbVar5 = pbVar5 + (uint)bVar13 * -2 + 1;
              pbVar8 = pbVar8 + (uint)bVar13 * -2 + 1;
            } while (bVar10);
            if ((((bVar10) && (pbVar7[-1] == 0x20)) && (0 < (int)(pbVar7 + (-1 - (int)__s)))) &&
               (pEVar4 = EVP_PKEY_asn1_find_str
                                   ((ENGINE **)0x0,(char *)__s,(int)(pbVar7 + (-1 - (int)__s))),
               __s = local_48, pEVar4 != (EVP_PKEY_ASN1_METHOD *)0x0)) {
              iVar1 = *(int *)(pEVar4 + 0x5c);
              goto joined_r0x08155119;
            }
          }
          goto LAB_08154e50;
        }
      }
      goto LAB_08154ed0;
    }
    iVar1 = 0xb;
    pbVar7 = (byte *)name;
    pbVar5 = (byte *)0x822a89b;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar10 = *pbVar7 < *pbVar5;
      bVar11 = *pbVar7 == *pbVar5;
      pbVar7 = pbVar7 + (uint)bVar13 * -2 + 1;
      pbVar5 = pbVar5 + (uint)bVar13 * -2 + 1;
    } while (bVar11);
    if (bVar11) {
      sVar2 = strlen((char *)__s);
      bVar10 = sVar2 == 0xb;
      if (0xb < (int)sVar2) {
        pbVar7 = __s + (sVar2 - 10);
        iVar1 = 0xb;
        pbVar5 = pbVar7;
        pbVar8 = (byte *)0x822a89b;
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar10 = *pbVar5 == *pbVar8;
          pbVar5 = pbVar5 + (uint)bVar13 * -2 + 1;
          pbVar8 = pbVar8 + (uint)bVar13 * -2 + 1;
        } while (bVar10);
        if (((bVar10) && (pbVar7[-1] == 0x20)) &&
           ((0 < (int)(pbVar7 + (-1 - (int)__s)) &&
            (pEVar4 = EVP_PKEY_asn1_find_str(&local_38,(char *)__s,(int)(pbVar7 + (-1 - (int)__s))),
            __s = local_48, pEVar4 != (EVP_PKEY_ASN1_METHOD *)0x0)))) {
          iVar1 = *(int *)(pEVar4 + 0x38);
          if (local_38 != (ENGINE *)0x0) {
            ENGINE_finish(local_38);
            __s = local_48;
          }
joined_r0x08155119:
          local_48 = __s;
          if (iVar1 != 0) goto LAB_08154ed0;
        }
      }
    }
    else {
      iVar1 = 0x11;
      pbVar7 = __s;
      pbVar5 = (byte *)"X509 CERTIFICATE";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar10 = *pbVar7 < *pbVar5;
        bVar11 = *pbVar7 == *pbVar5;
        pbVar7 = pbVar7 + (uint)bVar13 * -2 + 1;
        pbVar5 = pbVar5 + (uint)bVar13 * -2 + 1;
      } while (bVar11);
      bVar12 = (!bVar10 && !bVar11) == bVar10;
      if (bVar12) {
        iVar1 = 0xc;
        pcVar6 = name;
        pcVar9 = "CERTIFICATE";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar12 = *pcVar6 == *pcVar9;
          pcVar6 = pcVar6 + (uint)bVar13 * -2 + 1;
          pcVar9 = pcVar9 + (uint)bVar13 * -2 + 1;
        } while (bVar12);
        if (bVar12) goto LAB_08154ed0;
      }
      iVar1 = 0x18;
      pbVar7 = __s;
      pbVar5 = (byte *)"NEW CERTIFICATE REQUEST";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar12 = *pbVar7 == *pbVar5;
        pbVar7 = pbVar7 + (uint)bVar13 * -2 + 1;
        pbVar5 = pbVar5 + (uint)bVar13 * -2 + 1;
      } while (bVar12);
      if (bVar12) {
        iVar1 = 0x14;
        pcVar6 = name;
        pcVar9 = "CERTIFICATE REQUEST";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar12 = *pcVar6 == *pcVar9;
          pcVar6 = pcVar6 + (uint)bVar13 * -2 + 1;
          pcVar9 = pcVar9 + (uint)bVar13 * -2 + 1;
        } while (bVar12);
        if (bVar12) goto LAB_08154ed0;
      }
      iVar1 = 0xc;
      pbVar7 = __s;
      pbVar5 = (byte *)0x822a678;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar12 = *pbVar7 == *pbVar5;
        pbVar7 = pbVar7 + (uint)bVar13 * -2 + 1;
        pbVar5 = pbVar5 + (uint)bVar13 * -2 + 1;
      } while (bVar12);
      if (bVar12) {
        iVar1 = 0x14;
        pcVar6 = name;
        pcVar9 = "TRUSTED CERTIFICATE";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar12 = *pcVar6 == *pcVar9;
          pcVar6 = pcVar6 + (uint)bVar13 * -2 + 1;
          pcVar9 = pcVar9 + (uint)bVar13 * -2 + 1;
        } while (bVar12);
        if (!bVar12) {
          iVar1 = 6;
          pcVar6 = name;
          pcVar9 = "PKCS7";
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar12 = *pcVar6 == *pcVar9;
            pcVar6 = pcVar6 + (uint)bVar13 * -2 + 1;
            pcVar9 = pcVar9 + (uint)bVar13 * -2 + 1;
          } while (bVar12);
          if (!bVar12) {
            if (*name == 'C') {
              bVar10 = name[1] == 'M';
              if (((bVar10) && (bVar10 = name[2] == 'S', bVar10)) &&
                 (bVar10 = name[3] == '\0', bVar10)) goto LAB_08154ed0;
              iVar1 = 6;
              pbVar7 = __s;
              pbVar5 = (byte *)0x822f4b1;
              do {
                if (iVar1 == 0) break;
                iVar1 = iVar1 + -1;
                bVar10 = *pbVar7 == *pbVar5;
                pbVar7 = pbVar7 + (uint)bVar13 * -2 + 1;
                pbVar5 = pbVar5 + (uint)bVar13 * -2 + 1;
              } while (bVar10);
              if (bVar10) goto LAB_08154eb5;
            }
            goto LAB_08154e50;
          }
        }
        goto LAB_08154ed0;
      }
      bVar10 = (!bVar10 && !bVar11) == bVar10;
      if (bVar10) {
        iVar1 = 0x14;
        pcVar6 = name;
        pcVar9 = "TRUSTED CERTIFICATE";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar10 = *pcVar6 == *pcVar9;
          pcVar6 = pcVar6 + (uint)bVar13 * -2 + 1;
          pcVar9 = pcVar9 + (uint)bVar13 * -2 + 1;
        } while (bVar10);
        if (bVar10) goto LAB_08154ed0;
      }
      iVar1 = 0x14;
      pbVar7 = __s;
      pbVar5 = (byte *)"PKCS #7 SIGNED DATA";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar10 = *pbVar7 == *pbVar5;
        pbVar7 = pbVar7 + (uint)bVar13 * -2 + 1;
        pbVar5 = pbVar5 + (uint)bVar13 * -2 + 1;
      } while (bVar10);
      if (bVar10) {
        iVar1 = 6;
        pcVar6 = name;
        pcVar9 = "PKCS7";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar10 = *pcVar6 == *pcVar9;
          pcVar6 = pcVar6 + (uint)bVar13 * -2 + 1;
          pcVar9 = pcVar9 + (uint)bVar13 * -2 + 1;
        } while (bVar10);
        if (bVar10) goto LAB_08154ed0;
      }
      iVar1 = 6;
      pbVar7 = __s;
      pbVar5 = (byte *)0x822f4b1;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar10 = *pbVar7 == *pbVar5;
        pbVar7 = pbVar7 + (uint)bVar13 * -2 + 1;
        pbVar5 = pbVar5 + (uint)bVar13 * -2 + 1;
      } while (bVar10);
      if ((bVar10) && (*name == 'C')) {
LAB_08154eb5:
        if ((name[1] == 'M') && ((name[2] == 'S' && (name[3] == '\0')))) goto LAB_08154ed0;
      }
    }
LAB_08154e50:
    CRYPTO_free(__s);
    CRYPTO_free(local_44);
    CRYPTO_free(local_40);
  } while( true );
}

