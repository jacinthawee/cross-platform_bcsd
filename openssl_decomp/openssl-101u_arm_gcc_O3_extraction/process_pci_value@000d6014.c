
void process_pci_value(CONF_VALUE *param_1,ASN1_OBJECT **param_2,ASN1_INTEGER **param_3,
                      ASN1_OBJECT **param_4)

{
  ASN1_OBJECT *pAVar1;
  ASN1_OBJECT *pAVar2;
  uchar *puVar3;
  uchar *puVar4;
  BIO *b;
  size_t __n;
  int iVar5;
  char *pcVar6;
  ASN1_OBJECT *pAVar7;
  int iVar8;
  size_t local_830;
  undefined auStack_82c [2048];
  int local_2c;
  
  pcVar6 = param_1->name;
  local_2c = __stack_chk_guard;
  pAVar1 = (ASN1_OBJECT *)strcmp(pcVar6,"language");
  if (pAVar1 == (ASN1_OBJECT *)0x0) {
    if (*param_2 == (ASN1_OBJECT *)0x0) {
      pAVar1 = OBJ_txt2obj(param_1->value,0);
      *param_2 = pAVar1;
      if (pAVar1 != (ASN1_OBJECT *)0x0) goto LAB_000d61f8;
      iVar8 = 0x5b;
      iVar5 = 0x6e;
    }
    else {
      iVar8 = 0x55;
      iVar5 = 0x9b;
    }
  }
  else {
    pAVar1 = (ASN1_OBJECT *)strcmp(pcVar6,"pathlen");
    if (pAVar1 != (ASN1_OBJECT *)0x0) {
      pAVar2 = (ASN1_OBJECT *)strcmp(pcVar6,"policy");
      if (pAVar2 == (ASN1_OBJECT *)0x0) {
        pAVar7 = *param_4;
        if (*param_4 == (ASN1_OBJECT *)0x0) {
          pAVar1 = (ASN1_OBJECT *)ASN1_OCTET_STRING_new();
          *param_4 = pAVar1;
          pAVar7 = pAVar1;
          pAVar2 = (ASN1_OBJECT *)0x1;
          if (pAVar1 == (ASN1_OBJECT *)0x0) {
            ERR_put_error(0x22,0x96,0x41,"v3_pci.c",0x72);
            ERR_add_error_data(6,"section:",param_1->section,",name:",param_1->name,",value:",
                               param_1->value);
            goto LAB_000d6094;
          }
        }
        pAVar1 = pAVar2;
        pcVar6 = param_1->value;
        iVar5 = strncmp(pcVar6,"hex:",4);
        if (iVar5 == 0) {
          puVar3 = string_to_hex(pcVar6 + 4,(long *)&local_830);
          if (puVar3 == (uchar *)0x0) {
            iVar8 = 0x7e;
            iVar5 = 0x71;
          }
          else {
            puVar4 = (uchar *)CRYPTO_realloc((uchar *)(*param_4)->nid,
                                             (int)((*param_4)->sn + local_830 + 1),"v3_pci.c",0x84);
            if (puVar4 != (uchar *)0x0) {
              (*param_4)->nid = (int)puVar4;
              memcpy((uchar *)(*param_4)->nid + (int)(*param_4)->sn,puVar3,local_830);
              pAVar1 = *param_4;
              pcVar6 = pAVar1->sn;
              pAVar1->sn = pcVar6 + local_830;
              ((uchar *)pAVar1->nid)[(int)(pcVar6 + local_830)] = '\0';
              CRYPTO_free(puVar3);
              goto LAB_000d61f8;
            }
            CRYPTO_free(puVar3);
            (*param_4)->nid = 0;
            iVar5 = 0x41;
            (*param_4)->sn = (char *)0x0;
            iVar8 = 0x93;
          }
        }
        else {
          puVar3 = (uchar *)strncmp(pcVar6,"file:",5);
          if (puVar3 == (uchar *)0x0) {
            b = BIO_new_file(pcVar6 + 5,"r");
            if (b == (BIO *)0x0) {
              iVar8 = 0x9d;
              iVar5 = 0x20;
            }
            else {
              do {
                while( true ) {
                  __n = BIO_read(b,auStack_82c,0x800);
                  if ((int)__n < 1) break;
                  puVar3 = (uchar *)CRYPTO_realloc((uchar *)(*param_4)->nid,
                                                   (int)((*param_4)->sn + __n + 1),"v3_pci.c",0xa7);
                  if (puVar3 == (uchar *)0x0) {
                    BIO_free_all(b);
                    goto LAB_000d631c;
                  }
                  (*param_4)->nid = (int)puVar3;
                  memcpy((uchar *)(*param_4)->nid + (int)(*param_4)->sn,auStack_82c,__n);
                  pAVar2 = *param_4;
                  pcVar6 = pAVar2->sn;
                  pAVar2->sn = pcVar6 + __n;
                  ((uchar *)pAVar2->nid)[(int)(pcVar6 + __n)] = '\0';
                }
                if (__n != 0) {
                  BIO_free_all(b);
                  iVar8 = 0xb4;
                  iVar5 = 0x20;
                  goto LAB_000d6154;
                }
                iVar5 = BIO_test_flags(b,8);
              } while (iVar5 != 0);
              BIO_free_all(b);
              if (puVar3 != (uchar *)0x0) goto LAB_000d61f8;
LAB_000d631c:
              iVar8 = 0xd4;
              iVar5 = 0x41;
            }
          }
          else {
            iVar5 = strncmp(pcVar6,"text:",5);
            if (iVar5 == 0) {
              local_830 = strlen(pcVar6 + 5);
              puVar3 = (uchar *)CRYPTO_realloc((uchar *)pAVar7->nid,
                                               (int)(pAVar7->sn + local_830 + 1),"v3_pci.c",0xbb);
              if (puVar3 != (uchar *)0x0) {
                pcVar6 = param_1->value;
                (*param_4)->nid = (int)puVar3;
                memcpy((uchar *)(*param_4)->nid + (int)(*param_4)->sn,pcVar6 + 5,local_830);
                pAVar1 = *param_4;
                pcVar6 = pAVar1->sn;
                pAVar1->sn = pcVar6 + local_830;
                ((uchar *)pAVar1->nid)[(int)(pcVar6 + local_830)] = '\0';
                goto LAB_000d61f8;
              }
              (*param_4)->nid = 0;
              iVar5 = 0x41;
              (*param_4)->sn = (char *)0x0;
              iVar8 = 0xc9;
            }
            else {
              iVar8 = 0xcf;
              iVar5 = 0x98;
            }
          }
        }
LAB_000d6154:
        ERR_put_error(0x22,0x96,iVar5,"v3_pci.c",iVar8);
        ERR_add_error_data(6,"section:",param_1->section,",name:",param_1->name,",value:",
                           param_1->value);
        if (pAVar1 != (ASN1_OBJECT *)0x0) {
          ASN1_OCTET_STRING_free((ASN1_OCTET_STRING *)*param_4);
          pAVar1 = (ASN1_OBJECT *)0x0;
          *param_4 = (ASN1_OBJECT *)0x0;
        }
        goto LAB_000d6094;
      }
LAB_000d61f8:
      pAVar1 = (ASN1_OBJECT *)0x1;
      goto LAB_000d6094;
    }
    if (*param_3 == (ASN1_INTEGER *)0x0) {
      pAVar1 = (ASN1_OBJECT *)X509V3_get_value_int(param_1,param_3);
      if (pAVar1 != (ASN1_OBJECT *)0x0) goto LAB_000d61f8;
      iVar8 = 0x68;
      iVar5 = 0x9c;
    }
    else {
      iVar8 = 0x62;
      iVar5 = 0x9d;
    }
  }
  ERR_put_error(0x22,0x96,iVar5,"v3_pci.c",iVar8);
  ERR_add_error_data(6,"section:",param_1->section,",name:",param_1->name,",value:",param_1->value);
LAB_000d6094:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(pAVar1);
  }
  return;
}

