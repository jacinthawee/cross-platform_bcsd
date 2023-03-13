
char * X509_NAME_oneline(X509_NAME *a,char *buf,int size)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  ASN1_OBJECT *pAVar4;
  char *pcVar5;
  int iVar6;
  ASN1_OBJECT **ppAVar7;
  size_t __n;
  char *pcVar8;
  uint uVar9;
  int iVar10;
  byte *pbVar11;
  uint uVar12;
  int in_GS_OFFSET;
  int local_a8;
  char *local_a4;
  int local_a0;
  BUF_MEM *local_94;
  char *local_90;
  uint local_80 [4];
  char local_70 [80];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_90 = buf;
  if (buf == (char *)0x0) {
    local_94 = BUF_MEM_new();
    if ((local_94 == (BUF_MEM *)0x0) || (iVar6 = BUF_MEM_grow(local_94,200), iVar6 == 0)) {
LAB_0815be64:
      ERR_put_error(0xb,0x74,0x41,"x509_obj.c",0xe2);
LAB_0815be47:
      BUF_MEM_free(local_94);
      local_90 = (char *)0x0;
      goto LAB_0815be08;
    }
    *local_94->data = '\0';
    if (a == (X509_NAME *)0x0) {
      local_90 = local_94->data;
      iVar6 = 199;
      CRYPTO_free(local_94);
      size = 200;
      goto LAB_0815bed8;
    }
    size = 200;
  }
  else {
    if (size == 0) {
      local_90 = (char *)0x0;
      goto LAB_0815be08;
    }
    local_94 = (BUF_MEM *)0x0;
    if (a == (X509_NAME *)0x0) {
      iVar6 = size + -1;
LAB_0815bed8:
      strncpy(local_90,"NO X509_NAME",size);
      local_90[iVar6] = '\0';
      goto LAB_0815be08;
    }
  }
  local_a0 = 0;
  for (local_a8 = 0; iVar6 = sk_num((_STACK *)a->entries), local_a8 < iVar6; local_a8 = local_a8 + 1
      ) {
    ppAVar7 = (ASN1_OBJECT **)sk_value((_STACK *)a->entries,local_a8);
    iVar6 = OBJ_obj2nid(*ppAVar7);
    if ((iVar6 == 0) || (local_a4 = OBJ_nid2sn(iVar6), local_a4 == (char *)0x0)) {
      i2t_ASN1_OBJECT(local_70,0x50,*ppAVar7);
      local_a4 = local_70;
    }
    __n = strlen(local_a4);
    pAVar4 = ppAVar7[1];
    pcVar5 = pAVar4->sn;
    if (0x100000 < (int)pcVar5) {
      iVar6 = 0x7b;
LAB_0815be31:
      ERR_put_error(0xb,0x74,0x86,"x509_obj.c",iVar6);
      goto LAB_0815be47;
    }
    iVar6 = pAVar4->nid;
    if ((pAVar4->ln == (char **)0x1b) && (((uint)pcVar5 & 3) == 0)) {
      local_80[2] = 0;
      local_80[1] = 0;
      local_80[0] = 0;
      if (0 < (int)pcVar5) {
        pcVar8 = (char *)0x0;
        do {
          if (pcVar8[iVar6] != '\0') {
            local_80[(uint)pcVar8 & 3] = 1;
          }
          pcVar8 = pcVar8 + 1;
        } while (pcVar5 != pcVar8);
        if ((local_80[0] | local_80[1] | local_80[2]) != 0) goto LAB_0815bba3;
      }
      uVar12 = 0;
      local_80[2] = 0;
      local_80[1] = 0;
      local_80[0] = 0;
      local_80[3] = 1;
      if ((int)pcVar5 < 1) goto LAB_0815bdd7;
LAB_0815bbd0:
      pcVar8 = (char *)0x0;
      iVar10 = 0;
      uVar9 = uVar12;
      while( true ) {
        if (uVar9 != 0) {
          iVar1 = iVar10 + 1;
          iVar10 = iVar10 + 4;
          if ((byte)(pcVar8[iVar6] - 0x20U) < 0x5f) {
            iVar10 = iVar1;
          }
        }
        pcVar8 = pcVar8 + 1;
        if (pcVar5 == pcVar8) break;
        uVar9 = local_80[(uint)pcVar8 & 3];
      }
    }
    else {
LAB_0815bba3:
      local_80[3] = 1;
      local_80[2] = 1;
      local_80[1] = 1;
      local_80[0] = 1;
      uVar12 = 1;
      if (0 < (int)pcVar5) goto LAB_0815bbd0;
LAB_0815bdd7:
      iVar10 = 0;
    }
    local_80[3] = 1;
    iVar6 = iVar10 + 2 + __n + local_a0;
    if (0x100000 < iVar6) {
      iVar6 = 0xac;
      goto LAB_0815be31;
    }
    if (local_94 == (BUF_MEM *)0x0) {
      pcVar8 = buf;
      if (size <= iVar6) goto LAB_0815bdf9;
    }
    else {
      iVar10 = BUF_MEM_grow(local_94,iVar6 + 1);
      if (iVar10 == 0) goto LAB_0815be64;
      pcVar8 = local_94->data;
    }
    pcVar8 = pcVar8 + local_a0;
    *pcVar8 = '/';
    memcpy(pcVar8 + 1,local_a4,__n);
    pcVar8[__n + 1] = '=';
    pbVar11 = (byte *)(pcVar8 + __n + 2);
    iVar10 = ppAVar7[1]->nid;
    if (0 < (int)pcVar5) {
      uVar9 = 0;
      while( true ) {
        if (uVar12 != 0) {
          bVar3 = *(byte *)(iVar10 + uVar9);
          uVar12 = (uint)bVar3;
          if (uVar12 - 0x20 < 0x5f) {
            *pbVar11 = bVar3;
            pbVar11 = pbVar11 + 1;
          }
          else {
            *pbVar11 = 0x5c;
            bVar3 = "0123456789ABCDEF"[(int)uVar12 >> 4];
            bVar2 = "0123456789ABCDEF"[uVar12 & 0xf];
            pbVar11[1] = 0x78;
            pbVar11[2] = bVar3;
            pbVar11[3] = bVar2;
            pbVar11 = pbVar11 + 4;
          }
        }
        if (pcVar5 == (char *)(uVar9 + 1)) break;
        uVar9 = uVar9 + 1;
        uVar12 = local_80[uVar9 & 3];
      }
    }
    *pbVar11 = 0;
    local_a0 = iVar6;
  }
  if (local_94 != (BUF_MEM *)0x0) {
    local_90 = local_94->data;
    CRYPTO_free(local_94);
  }
LAB_0815bdf9:
  if (local_a8 == 0) {
    *local_90 = '\0';
  }
LAB_0815be08:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_90;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

