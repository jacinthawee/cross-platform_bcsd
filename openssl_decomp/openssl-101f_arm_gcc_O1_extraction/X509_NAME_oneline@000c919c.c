
char * X509_NAME_oneline(X509_NAME *a,char *buf,int size)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  ASN1_OBJECT **ppAVar4;
  char *pcVar5;
  size_t __n;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  ASN1_OBJECT *pAVar9;
  char *pcVar10;
  uint uVar11;
  BUF_MEM *pBVar12;
  char *pcVar13;
  int iVar14;
  byte *pbVar15;
  byte *pbVar16;
  int iVar17;
  BUF_MEM *local_a4;
  BUF_MEM *local_9c;
  int local_98;
  char *local_8c [4];
  char acStack_7c [80];
  int local_2c;
  
  local_2c = __TMC_END__;
  if (buf == (char *)0x0) {
    local_9c = BUF_MEM_new();
    if (local_9c == (BUF_MEM *)0x0) {
      ERR_put_error(0xb,0x74,0x41,"x509_obj.c",0xde);
      goto LAB_000c92b2;
    }
    iVar7 = BUF_MEM_grow(local_9c,200);
    local_a4 = local_9c;
    if (iVar7 == 0) {
LAB_000c9294:
      ERR_put_error(0xb,0x74,0x41,"x509_obj.c",0xde);
      BUF_MEM_free(local_a4);
      local_9c = (BUF_MEM *)0x0;
      goto LAB_000c92b2;
    }
    *local_9c->data = '\0';
    if (a == (X509_NAME *)0x0) {
      pBVar12 = (BUF_MEM *)local_9c->data;
      iVar7 = 199;
      CRYPTO_free(local_9c);
      size = 200;
      local_9c = pBVar12;
      goto LAB_000c943c;
    }
    local_98 = 200;
  }
  else {
    if (a == (X509_NAME *)0x0) {
      iVar7 = size + -1;
      local_9c = (BUF_MEM *)buf;
LAB_000c943c:
      strncpy((char *)local_9c,"NO X509_NAME",size);
      *(undefined *)((int)&local_9c->length + iVar7) = 0;
      goto LAB_000c92b2;
    }
    local_a4 = (BUF_MEM *)0x0;
    local_98 = size;
  }
  iVar14 = 0;
  iVar3 = sk_num((_STACK *)a->entries);
  iVar7 = 0;
  local_9c = (BUF_MEM *)buf;
  if (0 < iVar3) {
    do {
      ppAVar4 = (ASN1_OBJECT **)sk_value((_STACK *)a->entries,iVar14);
      iVar3 = OBJ_obj2nid(*ppAVar4);
      if ((iVar3 == 0) || (pcVar5 = OBJ_nid2sn(iVar3), pcVar5 == (char *)0x0)) {
        pcVar5 = acStack_7c;
        i2t_ASN1_OBJECT(pcVar5,0x50,*ppAVar4);
      }
      __n = strlen(pcVar5);
      pAVar9 = ppAVar4[1];
      pcVar13 = pAVar9->sn;
      iVar3 = pAVar9->nid;
      if ((pAVar9->ln == (char **)0x1b) &&
         (pcVar10 = (char *)((uint)pcVar13 & 3), pcVar10 == (char *)0x0)) {
        local_8c[0] = pcVar10;
        local_8c[1] = pcVar10;
        local_8c[2] = pcVar10;
        if (0 < (int)pcVar13) {
          do {
            if (pcVar10[iVar3] != '\0') {
              local_8c[(uint)pcVar10 & 3] = (char *)0x1;
            }
            pcVar10 = pcVar10 + 1;
          } while (pcVar10 != pcVar13);
          if (((uint)local_8c[2] | (uint)local_8c[0] | (uint)local_8c[1]) != 0) goto LAB_000c9256;
        }
        pcVar10 = (char *)0x0;
        local_8c[3] = (char *)0x1;
        local_8c[2] = (char *)0x0;
        local_8c[1] = (char *)0x0;
        local_8c[0] = (char *)0x0;
      }
      else {
LAB_000c9256:
        pcVar10 = (char *)0x1;
        local_8c[3] = (char *)0x1;
        local_8c[2] = (char *)0x1;
        local_8c[1] = (char *)0x1;
        local_8c[0] = (char *)0x1;
      }
      local_8c[3] = (char *)0x1;
      if ((int)pcVar13 < 1) {
        iVar17 = 0;
      }
      else {
        pcVar8 = (char *)0x0;
        iVar17 = 0;
        pcVar6 = pcVar10;
        while( true ) {
          if (pcVar6 != (char *)0x0) {
            if ((byte)pcVar8[iVar3] - 0x20 < 0x5f) {
              iVar17 = iVar17 + 1;
            }
            else {
              iVar17 = iVar17 + 4;
            }
          }
          pcVar8 = pcVar8 + 1;
          if (pcVar8 == pcVar13) break;
          pcVar6 = local_8c[(uint)pcVar8 & 3];
        }
      }
      iVar3 = __n + 2 + iVar17 + iVar7;
      if (local_a4 == (BUF_MEM *)0x0) {
        pcVar6 = buf;
        if (local_98 <= iVar3) goto LAB_000c93b4;
      }
      else {
        iVar17 = BUF_MEM_grow(local_a4,iVar3 + 1);
        if (iVar17 == 0) goto LAB_000c9294;
        pcVar6 = local_a4->data;
      }
      pcVar8 = pcVar6 + iVar7 + 1;
      pcVar6[iVar7] = '/';
      memcpy(pcVar8,pcVar5,__n);
      pcVar8[__n] = '=';
      pbVar15 = (byte *)(pcVar8 + __n + 1);
      iVar7 = ppAVar4[1]->nid;
      if (0 < (int)pcVar13) {
        pcVar5 = (char *)0x0;
        pbVar16 = pbVar15;
        while( true ) {
          pbVar15 = pbVar16;
          if (pcVar10 != (char *)0x0) {
            uVar11 = (uint)(byte)pcVar5[iVar7];
            if (uVar11 - 0x20 < 0x5f) {
              *pbVar16 = pcVar5[iVar7];
              pbVar15 = pbVar16 + 1;
            }
            else {
              *pbVar16 = 0x5c;
              pbVar15 = pbVar16 + 4;
              bVar2 = "0123456789ABCDEF"[(int)uVar11 >> 4];
              bVar1 = "0123456789ABCDEF"[uVar11 & 0xf];
              pbVar16[1] = 0x78;
              pbVar16[2] = bVar2;
              pbVar16[3] = bVar1;
            }
          }
          pcVar5 = pcVar5 + 1;
          if (pcVar5 == pcVar13) break;
          pcVar10 = local_8c[(uint)pcVar5 & 3];
          pbVar16 = pbVar15;
        }
      }
      *pbVar15 = 0;
      iVar14 = iVar14 + 1;
      iVar17 = sk_num((_STACK *)a->entries);
      iVar7 = iVar3;
    } while (iVar14 < iVar17);
  }
  if (local_a4 != (BUF_MEM *)0x0) {
    local_9c = (BUF_MEM *)local_a4->data;
    CRYPTO_free(local_a4);
  }
LAB_000c93b4:
  if (iVar14 == 0) {
    *(undefined *)&local_9c->length = 0;
  }
LAB_000c92b2:
  if (local_2c == __TMC_END__) {
    return (char *)local_9c;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

