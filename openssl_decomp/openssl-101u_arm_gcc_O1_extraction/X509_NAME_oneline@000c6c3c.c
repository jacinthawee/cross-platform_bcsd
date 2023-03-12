
char * X509_NAME_oneline(X509_NAME *a,char *buf,int size)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  ASN1_OBJECT **ppAVar4;
  char *pcVar5;
  size_t __n;
  int iVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  ASN1_OBJECT *pAVar10;
  char *pcVar11;
  byte *pbVar12;
  byte *pbVar13;
  char *pcVar14;
  char *pcVar15;
  int iVar16;
  BUF_MEM *local_a4;
  char *local_9c;
  int local_98;
  char *local_8c [4];
  char acStack_7c [80];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (buf == (char *)0x0) {
    local_a4 = BUF_MEM_new();
    if ((local_a4 == (BUF_MEM *)0x0) || (iVar7 = BUF_MEM_grow(local_a4,200), iVar7 == 0)) {
LAB_000c6ed6:
      ERR_put_error(0xb,0x74,0x41,"x509_obj.c",0xe2);
LAB_000c6ec4:
      BUF_MEM_free(local_a4);
      local_9c = (char *)0x0;
      goto LAB_000c6c6a;
    }
    *local_a4->data = '\0';
    if (a == (X509_NAME *)0x0) {
      local_9c = local_a4->data;
      iVar7 = 199;
      CRYPTO_free(local_a4);
      size = 200;
      goto LAB_000c6efe;
    }
    local_98 = 200;
  }
  else {
    local_9c = (char *)size;
    if (size == 0) goto LAB_000c6c6a;
    if (a == (X509_NAME *)0x0) {
      iVar7 = size + -1;
      local_9c = buf;
LAB_000c6efe:
      strncpy(local_9c,"NO X509_NAME",size);
      local_9c[iVar7] = '\0';
      goto LAB_000c6c6a;
    }
    local_a4 = (BUF_MEM *)0x0;
    local_98 = size;
  }
  iVar16 = 0;
  iVar3 = sk_num((_STACK *)a->entries);
  iVar7 = 0;
  if (0 < iVar3) {
    do {
      ppAVar4 = (ASN1_OBJECT **)sk_value((_STACK *)a->entries,iVar16);
      iVar3 = OBJ_obj2nid(*ppAVar4);
      if ((iVar3 == 0) || (pcVar5 = OBJ_nid2sn(iVar3), pcVar5 == (char *)0x0)) {
        pcVar5 = acStack_7c;
        i2t_ASN1_OBJECT(pcVar5,0x50,*ppAVar4);
      }
      __n = strlen(pcVar5);
      pAVar10 = ppAVar4[1];
      pcVar14 = pAVar10->sn;
      if (0x100000 < (int)pcVar14) {
        iVar7 = 0x7b;
LAB_000c6eb4:
        ERR_put_error(0xb,0x74,0x86,"x509_obj.c",iVar7);
        goto LAB_000c6ec4;
      }
      iVar3 = pAVar10->nid;
      if ((pAVar10->ln == (char **)0x1b) &&
         (pcVar15 = (char *)((uint)pcVar14 & 3), pcVar15 == (char *)0x0)) {
        local_8c[0] = pcVar15;
        local_8c[1] = pcVar15;
        local_8c[2] = pcVar15;
        if (0 < (int)pcVar14) {
          do {
            if (pcVar15[iVar3] != '\0') {
              local_8c[(uint)pcVar15 & 3] = (char *)0x1;
            }
            pcVar15 = pcVar15 + 1;
          } while (pcVar15 != pcVar14);
          if (((uint)local_8c[2] | (uint)local_8c[0] | (uint)local_8c[1]) != 0) goto LAB_000c6d14;
        }
        pcVar15 = (char *)0x0;
        local_8c[3] = (char *)0x1;
        local_8c[2] = (char *)0x0;
        local_8c[1] = (char *)0x0;
        local_8c[0] = (char *)0x0;
      }
      else {
LAB_000c6d14:
        pcVar15 = (char *)0x1;
        local_8c[3] = (char *)0x1;
        local_8c[2] = (char *)0x1;
        local_8c[1] = (char *)0x1;
        local_8c[0] = (char *)0x1;
      }
      local_8c[3] = (char *)0x1;
      if ((int)pcVar14 < 1) {
        iVar6 = 0;
      }
      else {
        pcVar11 = (char *)0x0;
        iVar6 = 0;
        pcVar8 = pcVar15;
        while( true ) {
          if (pcVar8 != (char *)0x0) {
            if ((byte)pcVar11[iVar3] - 0x20 < 0x5f) {
              iVar6 = iVar6 + 1;
            }
            else {
              iVar6 = iVar6 + 4;
            }
          }
          pcVar11 = pcVar11 + 1;
          if (pcVar11 == pcVar14) break;
          pcVar8 = local_8c[(uint)pcVar11 & 3];
        }
      }
      iVar3 = __n + 2 + iVar6 + iVar7;
      if (0x100000 < iVar3) {
        iVar7 = 0xac;
        goto LAB_000c6eb4;
      }
      if (local_a4 == (BUF_MEM *)0x0) {
        pcVar8 = buf;
        local_9c = buf;
        if (local_98 <= iVar3) goto LAB_000c6e38;
      }
      else {
        iVar6 = BUF_MEM_grow(local_a4,iVar3 + 1);
        if (iVar6 == 0) goto LAB_000c6ed6;
        pcVar8 = local_a4->data;
      }
      pcVar11 = pcVar8 + iVar7 + 1;
      pcVar8[iVar7] = '/';
      memcpy(pcVar11,pcVar5,__n);
      pcVar11[__n] = '=';
      pbVar12 = (byte *)(pcVar11 + __n + 1);
      iVar7 = ppAVar4[1]->nid;
      if (0 < (int)pcVar14) {
        pcVar5 = (char *)0x0;
        pbVar13 = pbVar12;
        while( true ) {
          pbVar12 = pbVar13;
          if (pcVar15 != (char *)0x0) {
            uVar9 = (uint)(byte)pcVar5[iVar7];
            if (uVar9 - 0x20 < 0x5f) {
              *pbVar13 = pcVar5[iVar7];
              pbVar12 = pbVar13 + 1;
            }
            else {
              *pbVar13 = 0x5c;
              pbVar12 = pbVar13 + 4;
              bVar1 = "0123456789ABCDEF"[(int)uVar9 >> 4];
              bVar2 = "0123456789ABCDEF"[uVar9 & 0xf];
              pbVar13[1] = 0x78;
              pbVar13[2] = bVar1;
              pbVar13[3] = bVar2;
            }
          }
          pcVar5 = pcVar5 + 1;
          if (pcVar5 == pcVar14) break;
          pcVar15 = local_8c[(uint)pcVar5 & 3];
          pbVar13 = pbVar12;
        }
      }
      *pbVar12 = 0;
      iVar16 = iVar16 + 1;
      iVar6 = sk_num((_STACK *)a->entries);
      iVar7 = iVar3;
    } while (iVar16 < iVar6);
  }
  local_9c = buf;
  if (local_a4 != (BUF_MEM *)0x0) {
    local_9c = local_a4->data;
    CRYPTO_free(local_a4);
  }
LAB_000c6e38:
  if (iVar16 == 0) {
    *local_9c = '\0';
  }
LAB_000c6c6a:
  if (local_2c == __stack_chk_guard) {
    return local_9c;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

