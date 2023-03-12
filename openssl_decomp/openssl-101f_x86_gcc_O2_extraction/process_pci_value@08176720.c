
int __regparm3
process_pci_value(CONF_VALUE *param_1_00,ASN1_OBJECT **param_2,ASN1_INTEGER **param_3,
                 ASN1_OCTET_STRING **param_1)

{
  char *pcVar1;
  uchar *puVar2;
  ASN1_OBJECT *pAVar3;
  uchar *puVar4;
  BIO *b;
  size_t __n;
  ASN1_OCTET_STRING *pAVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  char *pcVar9;
  byte *pbVar10;
  char *pcVar11;
  int in_GS_OFFSET;
  bool bVar12;
  bool bVar13;
  byte bVar14;
  int iVar15;
  int iVar16;
  uchar *local_83c;
  size_t local_824;
  undefined local_820 [2048];
  int local_20;
  
  bVar14 = 0;
  pbVar8 = (byte *)param_1_00->name;
  iVar6 = 9;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bVar12 = false;
  bVar13 = true;
  pbVar7 = pbVar8;
  pbVar10 = (byte *)0x8208b42;
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar12 = *pbVar7 < *pbVar10;
    bVar13 = *pbVar7 == *pbVar10;
    pbVar7 = pbVar7 + 1;
    pbVar10 = pbVar10 + 1;
  } while (bVar13);
  iVar6 = (int)(char)((!bVar12 && !bVar13) - bVar12);
  bVar12 = false;
  bVar13 = iVar6 == 0;
  if (bVar13) {
    if (*param_2 == (ASN1_OBJECT *)0x0) {
      pAVar3 = OBJ_txt2obj(param_1_00->value,0);
      *param_2 = pAVar3;
      if (pAVar3 != (ASN1_OBJECT *)0x0) goto LAB_08176998;
      iVar16 = 0x5b;
      iVar15 = 0x6e;
    }
    else {
      iVar16 = 0x55;
      iVar15 = 0x9b;
    }
  }
  else {
    iVar6 = 8;
    pbVar7 = pbVar8;
    pbVar10 = (byte *)"pathlen";
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      bVar12 = *pbVar7 < *pbVar10;
      bVar13 = *pbVar7 == *pbVar10;
      pbVar7 = pbVar7 + 1;
      pbVar10 = pbVar10 + 1;
    } while (bVar13);
    iVar6 = (int)(char)((!bVar12 && !bVar13) - bVar12);
    bVar12 = false;
    bVar13 = iVar6 == 0;
    if (!bVar13) {
      iVar6 = 7;
      pbVar7 = (byte *)0x823329a;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar12 = *pbVar8 < *pbVar7;
        bVar13 = *pbVar8 == *pbVar7;
        pbVar8 = pbVar8 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar13);
      iVar6 = (int)(char)((!bVar12 && !bVar13) - bVar12);
      if (iVar6 == 0) {
        bVar12 = false;
        pAVar5 = *param_1;
        bVar13 = pAVar5 == (ASN1_OCTET_STRING *)0x0;
        if (bVar13) {
          pAVar5 = ASN1_OCTET_STRING_new();
          bVar12 = true;
          bVar13 = pAVar5 == (ASN1_OCTET_STRING *)0x0;
          *param_1 = pAVar5;
          if (bVar13) {
            iVar16 = 0x78;
            iVar15 = 0x41;
            goto LAB_08176786;
          }
        }
        iVar15 = 4;
        pcVar1 = param_1_00->value;
        pcVar9 = pcVar1;
        pcVar11 = "hex:";
        do {
          if (iVar15 == 0) break;
          iVar15 = iVar15 + -1;
          bVar13 = *pcVar9 == *pcVar11;
          pcVar9 = pcVar9 + (uint)bVar14 * -2 + 1;
          pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
        } while (bVar13);
        if (bVar13) {
          puVar4 = string_to_hex(pcVar1 + 4,(long *)&local_824);
          if (puVar4 != (uchar *)0x0) {
            puVar2 = (uchar *)CRYPTO_realloc((*param_1)->data,local_824 + (*param_1)->length + 1,
                                             "v3_pci.c",0x8b);
            if (puVar2 == (uchar *)0x0) {
              CRYPTO_free(puVar4);
              (*param_1)->data = (uchar *)0x0;
              (*param_1)->length = 0;
              iVar16 = 0x9a;
              goto LAB_08176b80;
            }
            (*param_1)->data = puVar2;
            memcpy((*param_1)->data + (*param_1)->length,puVar4,local_824);
            pAVar5 = *param_1;
            iVar6 = local_824 + pAVar5->length;
            pAVar5->length = iVar6;
            pAVar5->data[iVar6] = '\0';
            CRYPTO_free(puVar4);
            goto LAB_08176998;
          }
          iVar16 = 0x85;
          iVar15 = 0x71;
        }
        else {
          iVar15 = 5;
          pcVar9 = pcVar1;
          pcVar11 = "file:";
          do {
            if (iVar15 == 0) break;
            iVar15 = iVar15 + -1;
            bVar13 = *pcVar9 == *pcVar11;
            pcVar9 = pcVar9 + (uint)bVar14 * -2 + 1;
            pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
          } while (bVar13);
          if (bVar13) {
            b = BIO_new_file(pcVar1 + 5,"r");
            if (b != (BIO *)0x0) {
              local_83c = (uchar *)0x0;
              do {
                while( true ) {
                  __n = BIO_read(b,local_820,0x800);
                  if ((int)__n < 1) break;
                  local_83c = (uchar *)CRYPTO_realloc((*param_1)->data,(*param_1)->length + __n + 1,
                                                      "v3_pci.c",0xb1);
                  if (local_83c == (uchar *)0x0) {
                    BIO_free_all(b);
                    goto LAB_08176b78;
                  }
                  (*param_1)->data = local_83c;
                  memcpy((*param_1)->data + (*param_1)->length,local_820,__n);
                  pAVar5 = *param_1;
                  iVar15 = pAVar5->length + __n;
                  pAVar5->length = iVar15;
                  pAVar5->data[iVar15] = '\0';
                }
                if (__n != 0) {
                  BIO_free_all(b);
                  iVar16 = 0xc0;
                  iVar15 = 0x20;
                  goto LAB_081768ac;
                }
                iVar15 = BIO_test_flags(b,8);
              } while (iVar15 != 0);
              BIO_free_all(b);
              if (local_83c == (uchar *)0x0) {
LAB_08176b78:
                iVar16 = 0xe4;
                goto LAB_08176b80;
              }
              goto LAB_08176998;
            }
            iVar16 = 0xa7;
            iVar15 = 0x20;
          }
          else {
            iVar15 = 5;
            pcVar9 = pcVar1;
            pcVar11 = "text:";
            do {
              if (iVar15 == 0) break;
              iVar15 = iVar15 + -1;
              bVar13 = *pcVar9 == *pcVar11;
              pcVar9 = pcVar9 + (uint)bVar14 * -2 + 1;
              pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
            } while (bVar13);
            if (bVar13) {
              local_824 = strlen(pcVar1 + 5);
              puVar4 = (uchar *)CRYPTO_realloc(pAVar5->data,local_824 + pAVar5->length + 1,
                                               "v3_pci.c",0xc9);
              if (puVar4 != (uchar *)0x0) {
                (*param_1)->data = puVar4;
                memcpy((*param_1)->data + (*param_1)->length,param_1_00->value + 5,local_824);
                pAVar5 = *param_1;
                iVar6 = local_824 + pAVar5->length;
                pAVar5->length = iVar6;
                pAVar5->data[iVar6] = '\0';
                goto LAB_08176998;
              }
              (*param_1)->data = (uchar *)0x0;
              (*param_1)->length = 0;
              iVar16 = 0xd7;
LAB_08176b80:
              iVar15 = 0x41;
            }
            else {
              iVar16 = 0xde;
              iVar15 = 0x98;
            }
          }
        }
LAB_081768ac:
        ERR_put_error(0x22,0x96,iVar15,"v3_pci.c",iVar16);
        ERR_add_error_data(6,"section:",param_1_00->section,",name:",param_1_00->name,",value:",
                           param_1_00->value);
        if (bVar12) {
          ASN1_OCTET_STRING_free(*param_1);
          *param_1 = (ASN1_OCTET_STRING *)0x0;
        }
      }
      else {
LAB_08176998:
        iVar6 = 1;
      }
      goto LAB_081767ba;
    }
    if (*param_3 == (ASN1_INTEGER *)0x0) {
      iVar6 = X509V3_get_value_int(param_1_00,param_3);
      if (iVar6 != 0) goto LAB_08176998;
      iVar16 = 0x6a;
      iVar15 = 0x9c;
    }
    else {
      iVar16 = 100;
      iVar15 = 0x9d;
    }
  }
LAB_08176786:
  ERR_put_error(0x22,0x96,iVar15,"v3_pci.c",iVar16);
  ERR_add_error_data(6,"section:",param_1_00->section,",name:",param_1_00->name,",value:",
                     param_1_00->value);
LAB_081767ba:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

