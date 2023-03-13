
/* WARNING: Could not reconcile some variable overlaps */

AUTHORITY_KEYID * v2i_AUTHORITY_KEYID(undefined4 param_1,int *param_2,_STACK *param_3)

{
  X509 *x;
  int iVar1;
  AUTHORITY_KEYID *pAVar2;
  X509_NAME *pXVar3;
  ASN1_INTEGER *a;
  GENERAL_NAME *data;
  X509_EXTENSION *ext;
  int iVar4;
  ASN1_STRING *a_00;
  X509_NAME *pXVar5;
  BUF_MEM *pBVar6;
  ASN1_STRING *a_01;
  char *pcVar7;
  byte *pbVar8;
  _STACK *st;
  undefined uVar9;
  undefined uVar10;
  bool bVar11;
  bool bVar12;
  byte bVar13;
  X509_NAME *local_2c;
  undefined4 local_28;
  char local_21;
  int *local_20;
  
  bVar13 = 0;
  local_21 = '\0';
  local_28 = (GENERAL_NAME *)((uint)local_28 & 0xffffff00);
  local_20 = param_2;
  for (iVar4 = 0; iVar1 = sk_num(param_3), iVar4 < iVar1; iVar4 = iVar4 + 1) {
    uVar9 = &local_2c < &DAT_00000008;
    uVar10 = &stack0x00000000 == (undefined *)0x34;
    local_2c = (X509_NAME *)sk_value(param_3,iVar4);
    pXVar3 = (X509_NAME *)local_2c->modified;
    iVar1 = 6;
    pXVar5 = pXVar3;
    pbVar8 = (byte *)0x82329d0;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      uVar9 = *(byte *)&pXVar5->entries < *pbVar8;
      uVar10 = *(byte *)&pXVar5->entries == *pbVar8;
      pXVar5 = (X509_NAME *)((int)pXVar5 + (uint)bVar13 * -2 + 1);
      pbVar8 = pbVar8 + (uint)bVar13 * -2 + 1;
    } while ((bool)uVar10);
    bVar11 = (!(bool)uVar9 && !(bool)uVar10) == (bool)uVar9;
    if (bVar11) {
      bVar11 = false;
      bVar12 = local_2c->bytes == (BUF_MEM *)0x0;
      if (bVar12) {
        local_28 = (GENERAL_NAME *)CONCAT31(local_28._1_3_,1);
      }
      else {
        iVar1 = 7;
        pBVar6 = local_2c->bytes;
        pbVar8 = (byte *)"always";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar11 = *(byte *)&pBVar6->length < *pbVar8;
          bVar12 = *(byte *)&pBVar6->length == *pbVar8;
          pBVar6 = (BUF_MEM *)((int)pBVar6 + (uint)bVar13 * -2 + 1);
          pbVar8 = pbVar8 + (uint)bVar13 * -2 + 1;
        } while (bVar12);
        local_28 = (GENERAL_NAME *)
                   ((uint)local_28 & 0xffffff00 |
                   (uint)(byte)(~-((!bVar11 && !bVar12) == bVar11) + 2));
      }
    }
    else {
      iVar1 = 7;
      pXVar5 = pXVar3;
      pcVar7 = "issuer";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar11 = *(char *)&pXVar5->entries == *pcVar7;
        pXVar5 = (X509_NAME *)((int)pXVar5 + (uint)bVar13 * -2 + 1);
        pcVar7 = pcVar7 + (uint)bVar13 * -2 + 1;
      } while (bVar11);
      if (!bVar11) {
        ERR_put_error(0x22,0x77,0x78,"v3_akey.c",0x8f);
        ERR_add_error_data(2,"name=",local_2c->modified);
        return (AUTHORITY_KEYID *)0x0;
      }
      bVar11 = false;
      bVar12 = local_2c->bytes == (BUF_MEM *)0x0;
      if (bVar12) {
        local_21 = '\x01';
      }
      else {
        iVar1 = 7;
        pBVar6 = local_2c->bytes;
        pbVar8 = (byte *)"always";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar11 = *(byte *)&pBVar6->length < *pbVar8;
          bVar12 = *(byte *)&pBVar6->length == *pbVar8;
          pBVar6 = (BUF_MEM *)((int)pBVar6 + (uint)bVar13 * -2 + 1);
          pbVar8 = pbVar8 + (uint)bVar13 * -2 + 1;
        } while (bVar12);
        local_21 = ~-((!bVar11 && !bVar12) == bVar11) + 2;
      }
    }
    local_2c = pXVar3;
  }
  if (local_20 != (int *)0x0) {
    x = (X509 *)local_20[1];
    if (x != (X509 *)0x0) {
      a_01 = (ASN1_STRING *)0x0;
      bVar11 = true;
      if ((char)local_28 != '\0') {
        iVar4 = X509_get_ext_by_NID(x,0x52,-1);
        if ((iVar4 < 0) || (ext = X509_get_ext(x,iVar4), ext == (X509_EXTENSION *)0x0)) {
          bVar11 = true;
          a_01 = (ASN1_STRING *)0x0;
        }
        else {
          a_01 = (ASN1_STRING *)X509V3_EXT_d2i(ext);
          bVar11 = a_01 == (ASN1_STRING *)0x0;
        }
        if (((char)local_28 == '\x02') && (bVar11)) {
          iVar1 = 0xa5;
          iVar4 = 0x7b;
          goto LAB_0816ec9f;
        }
      }
      if (((bool)(local_21 != '\0' & bVar11)) || (local_21 == '\x02')) {
        pXVar3 = X509_get_issuer_name(x);
        pXVar3 = X509_NAME_dup(pXVar3);
        local_2c = pXVar3;
        a = X509_get_serialNumber(x);
        a_00 = ASN1_STRING_dup(a);
        if ((pXVar3 == (X509_NAME *)0x0) || (a_00 == (ASN1_STRING *)0x0)) {
          ERR_put_error(0x22,0x77,0x7a,"v3_akey.c",0xaf);
        }
        else {
          pAVar2 = AUTHORITY_KEYID_new();
          if (pAVar2 != (AUTHORITY_KEYID *)0x0) {
            st = sk_new_null();
            if (((st != (_STACK *)0x0) && (data = GENERAL_NAME_new(), data != (GENERAL_NAME *)0x0))
               && (local_28 = data, iVar4 = sk_push(st,data), iVar4 != 0)) {
              local_28->type = 4;
              (local_28->d).directoryName = local_2c;
              goto LAB_0816ebb8;
            }
            ERR_put_error(0x22,0x77,0x41,"v3_akey.c",0xbb);
          }
        }
      }
      else {
        pAVar2 = AUTHORITY_KEYID_new();
        a_00 = (ASN1_INTEGER *)0x0;
        st = (_STACK *)0x0;
        local_2c = (X509_NAME *)0x0;
        if (pAVar2 != (AUTHORITY_KEYID *)0x0) {
LAB_0816ebb8:
          pAVar2->issuer = (GENERAL_NAMES *)st;
          pAVar2->serial = a_00;
          pAVar2->keyid = a_01;
          return pAVar2;
        }
      }
      X509_NAME_free(local_2c);
      ASN1_STRING_free(a_00);
      ASN1_STRING_free(a_01);
      return (AUTHORITY_KEYID *)0x0;
    }
    if (*local_20 == 1) {
      pAVar2 = AUTHORITY_KEYID_new();
      return pAVar2;
    }
  }
  iVar1 = 0x99;
  iVar4 = 0x79;
LAB_0816ec9f:
  ERR_put_error(0x22,0x77,iVar4,"v3_akey.c",iVar1);
  return (AUTHORITY_KEYID *)0x0;
}

