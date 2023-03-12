
/* WARNING: Type propagation algorithm not settling */

int asn1_i2d_ex_primitive(int *param_1,uchar **param_2,char *param_3,uint param_4,int param_5)

{
  bool bVar1;
  int iVar2;
  ASN1_BIT_STRING *pAVar3;
  uint *puVar4;
  int *piVar5;
  uchar ********ppppppppuVar6;
  uint uVar7;
  int iVar8;
  size_t *psVar9;
  size_t __n;
  undefined *__src;
  code *pcVar10;
  int constructed;
  bool bVar11;
  bool bVar12;
  undefined local_38 [8];
  uint local_30;
  uchar ********local_2c [2];
  
  uVar7 = *(uint *)(param_3 + 4);
  local_30 = uVar7;
  if ((*(int *)(param_3 + 0x10) != 0) &&
     (pcVar10 = *(code **)(*(int *)(param_3 + 0x10) + 0x18), pcVar10 != (code *)0x0)) {
    iVar2 = (*pcVar10)(param_1,0,&local_30,param_3);
    goto LAB_000b974a;
  }
  piVar5 = param_1;
  if (*param_3 == '\0') {
    if (uVar7 != 1) {
      puVar4 = (uint *)*param_1;
      if (puVar4 == (uint *)0x0) {
        return 0;
      }
LAB_000b9828:
      if (uVar7 == 0xfffffffc) {
        piVar5 = (int *)(puVar4 + 1);
        local_30 = *puVar4;
      }
      goto LAB_000b9836;
    }
    pAVar3 = (ASN1_BIT_STRING *)*param_1;
    if (pAVar3 == (ASN1_BIT_STRING *)0xffffffff) {
      return 0;
    }
joined_r0x000b995c:
    if (pAVar3 == (ASN1_BIT_STRING *)0x0) {
      if (*(int *)(param_3 + 0x14) == 0) {
        return 0;
      }
    }
    else if (0 < *(int *)(param_3 + 0x14)) {
      return 0;
    }
LAB_000b9964:
    uVar7 = local_30 - 0x10;
    iVar2 = 1;
    bVar12 = 0xfffffffc < local_30;
    bVar11 = local_30 == 0xfffffffd;
    if (!bVar11) {
      bVar12 = uVar7 != 0;
    }
    bVar1 = uVar7 == 1;
    if (!bVar12 || (bVar11 || bVar1)) {
      uVar7 = 1;
    }
    if (bVar12 && (!bVar11 && !bVar1)) {
      uVar7 = 0;
    }
    uVar7 = uVar7 ^ 1;
LAB_000b9770:
    constructed = 0;
  }
  else {
    puVar4 = (uint *)*param_1;
    if (puVar4 == (uint *)0x0) {
      return 0;
    }
    if (*param_3 != '\x05') goto LAB_000b9828;
    local_30 = puVar4[1];
LAB_000b9836:
    switch(local_30) {
    case 1:
      pAVar3 = (ASN1_BIT_STRING *)*piVar5;
      if (pAVar3 == (ASN1_BIT_STRING *)0xffffffff) {
        return 0;
      }
      if (uVar7 != 0xfffffffc) goto joined_r0x000b995c;
      goto LAB_000b9964;
    case 2:
    case 10:
      iVar2 = i2c_ASN1_INTEGER((ASN1_INTEGER *)*piVar5,(uchar **)0x0);
      break;
    case 3:
      iVar2 = i2c_ASN1_BIT_STRING((ASN1_BIT_STRING *)*piVar5,(uchar **)0x0);
      break;
    default:
      if ((*(int *)(param_3 + 0x14) != 0x800) || (-1 < ((ASN1_BIT_STRING *)*piVar5)->flags << 0x1b))
      {
        iVar2 = ((ASN1_BIT_STRING *)*piVar5)->length;
        break;
      }
      uVar7 = local_30 - 0x10;
      constructed = 2;
      bVar12 = 0xfffffffc < local_30;
      bVar11 = local_30 == 0xfffffffd;
      if (!bVar11) {
        bVar12 = uVar7 != 0;
      }
      bVar1 = uVar7 == 1;
      iVar2 = 0;
      if (!bVar12 || (bVar11 || bVar1)) {
        uVar7 = 1;
      }
      if (bVar12 && (!bVar11 && !bVar1)) {
        uVar7 = 0;
      }
      uVar7 = uVar7 ^ 1;
      goto LAB_000b9774;
    case 5:
      uVar7 = local_30 - 0x10;
      iVar2 = 0;
      bVar12 = 0xfffffffc < local_30;
      bVar11 = local_30 == 0xfffffffd;
      if (!bVar11) {
        bVar12 = uVar7 != 0;
      }
      bVar1 = uVar7 == 1;
      if (!bVar12 || (bVar11 || bVar1)) {
        uVar7 = 1;
      }
      if (bVar12 && (!bVar11 && !bVar1)) {
        uVar7 = 0;
      }
      uVar7 = uVar7 ^ 1;
      goto LAB_000b9770;
    case 6:
      iVar2 = ((ASN1_BIT_STRING *)*piVar5)->flags;
    }
LAB_000b974a:
    uVar7 = local_30 - 0x10;
    bVar12 = 0xfffffffc < local_30;
    bVar11 = local_30 == 0xfffffffd;
    if (!bVar11) {
      bVar12 = uVar7 != 0;
    }
    bVar1 = uVar7 == 1;
    if (!bVar12 || (bVar11 || bVar1)) {
      uVar7 = 1;
    }
    if (bVar12 && (!bVar11 && !bVar1)) {
      uVar7 = 0;
    }
    uVar7 = uVar7 ^ 1;
    if (iVar2 == -1) {
      return 0;
    }
    if (iVar2 != -2) goto LAB_000b9770;
    constructed = 2;
    iVar2 = 0;
  }
LAB_000b9774:
  if (param_4 == 0xffffffff) {
    param_4 = local_30;
  }
  if (param_2 == (uchar **)0x0) goto joined_r0x000b987c;
  if (uVar7 != 0) {
    ASN1_put_object(param_2,constructed,iVar2,param_4,param_5);
  }
  local_2c[0] = (uchar ********)*param_2;
  if ((*(int *)(param_3 + 0x10) != 0) &&
     (pcVar10 = *(code **)(*(int *)(param_3 + 0x10) + 0x18), pcVar10 != (code *)0x0)) {
    (*pcVar10)(param_1,local_2c[0],&local_30,param_3);
    goto joined_r0x000b986e;
  }
  if (*param_3 == '\0') {
    iVar8 = *(int *)(param_3 + 4);
    if (iVar8 == 1) goto LAB_000b97e8;
    pAVar3 = (ASN1_BIT_STRING *)*param_1;
    if (pAVar3 != (ASN1_BIT_STRING *)0x0) goto LAB_000b97e0;
    goto joined_r0x000b986e;
  }
  pAVar3 = (ASN1_BIT_STRING *)*param_1;
  if (pAVar3 == (ASN1_BIT_STRING *)0x0) goto joined_r0x000b986e;
  if (*param_3 == '\x05') {
    local_30 = pAVar3->type;
  }
  else {
    iVar8 = *(int *)(param_3 + 4);
LAB_000b97e0:
    if (iVar8 == -4) {
      param_1 = &pAVar3->type;
      local_30 = pAVar3->length;
    }
  }
LAB_000b97e8:
  switch(local_30) {
  case 1:
    iVar8 = *param_1;
    if (iVar8 == -1) break;
    if (*(int *)(param_3 + 4) != -4) {
      if (iVar8 == 0) {
        if (*(int *)(param_3 + 0x14) != 0) goto LAB_000b9924;
      }
      else if (*(int *)(param_3 + 0x14) < 1) goto LAB_000b9924;
      break;
    }
LAB_000b9924:
    local_38[0] = (undefined)iVar8;
    __n = 1;
    __src = local_38;
    if (local_2c[0] == (uchar ********)0x0) break;
    goto LAB_000b98d8;
  case 2:
  case 10:
    ppppppppuVar6 = local_2c[0];
    if (local_2c[0] != (uchar ********)0x0) {
      ppppppppuVar6 = (uchar ********)local_2c;
    }
    i2c_ASN1_INTEGER((ASN1_INTEGER *)*param_1,(uchar **)ppppppppuVar6);
    break;
  case 3:
    ppppppppuVar6 = local_2c[0];
    if (local_2c[0] != (uchar ********)0x0) {
      ppppppppuVar6 = (uchar ********)local_2c;
    }
    i2c_ASN1_BIT_STRING((ASN1_BIT_STRING *)*param_1,(uchar **)ppppppppuVar6);
    break;
  default:
    psVar9 = (size_t *)*param_1;
    if ((*(int *)(param_3 + 0x14) != 0x800) || (-1 < (int)(psVar9[3] << 0x1b))) {
      __src = (undefined *)psVar9[2];
      __n = *psVar9;
      goto LAB_000b98cc;
    }
    if (local_2c[0] != (uchar ********)0x0) {
      psVar9[2] = (size_t)local_2c[0];
      *psVar9 = 0;
    }
    break;
  case 5:
    __n = 0;
    __src = (undefined *)0x0;
    goto LAB_000b98cc;
  case 6:
    __src = *(undefined **)(*param_1 + 0x10);
    __n = *(size_t *)(*param_1 + 0xc);
LAB_000b98cc:
    if ((local_2c[0] != (uchar ********)0x0) && (__n != 0)) {
LAB_000b98d8:
      memcpy(local_2c[0],__src,__n);
    }
  }
joined_r0x000b986e:
  if (constructed == 0) {
    *param_2 = *param_2 + iVar2;
  }
  else {
    ASN1_put_eoc(param_2);
  }
joined_r0x000b987c:
  if (uVar7 == 0) {
    return iVar2;
  }
  iVar2 = ASN1_object_size(constructed,iVar2,param_4);
  return iVar2;
}

