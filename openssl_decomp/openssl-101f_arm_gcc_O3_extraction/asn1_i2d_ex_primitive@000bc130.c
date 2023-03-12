
/* WARNING: Type propagation algorithm not settling */

size_t * asn1_i2d_ex_primitive(int *param_1,uchar **param_2,char *param_3,uint param_4,int param_5)

{
  bool bVar1;
  uchar ********ppppppppuVar2;
  size_t *psVar3;
  ASN1_BIT_STRING *pAVar4;
  int *piVar5;
  uchar ********ppppppppuVar6;
  size_t sVar7;
  int iVar8;
  uchar **ppuVar9;
  uchar ********__n;
  size_t *psVar10;
  code *pcVar11;
  uint uVar12;
  uint uVar13;
  int constructed;
  bool bVar14;
  bool bVar15;
  undefined local_38;
  size_t local_30;
  uchar ********local_2c [2];
  
  sVar7 = *(size_t *)(param_3 + 4);
  local_30 = sVar7;
  if ((*(int *)(param_3 + 0x10) == 0) ||
     (pcVar11 = *(code **)(*(int *)(param_3 + 0x10) + 0x18), pcVar11 == (code *)0x0)) {
    piVar5 = param_1;
    if (*param_3 == '\0') {
      if (sVar7 != 1) {
        psVar3 = (size_t *)*param_1;
        if (psVar3 == (size_t *)0x0) {
          return (size_t *)0x0;
        }
LAB_000bc272:
        if (sVar7 == 0xfffffffc) {
          piVar5 = (int *)(psVar3 + 1);
          local_30 = *psVar3;
        }
        goto LAB_000bc280;
      }
      pAVar4 = (ASN1_BIT_STRING *)*param_1;
      if (pAVar4 == (ASN1_BIT_STRING *)0xffffffff) {
        return (size_t *)0x0;
      }
LAB_000bc2dc:
      if (pAVar4 == (ASN1_BIT_STRING *)0x0) {
        if (*(int *)(param_3 + 0x14) == 0) {
          return (size_t *)0x0;
        }
      }
      else if (0 < *(int *)(param_3 + 0x14)) {
        return (size_t *)0x0;
      }
      uVar12 = 1;
LAB_000bc3ae:
      uVar13 = uVar12 + 3;
      psVar3 = (size_t *)0x1;
      if (uVar13 != 0) {
        uVar13 = 1;
      }
    }
    else {
      psVar3 = (size_t *)*param_1;
      if (psVar3 == (size_t *)0x0) {
        return (size_t *)0x0;
      }
      if (*param_3 != '\x05') goto LAB_000bc272;
      local_30 = psVar3[1];
LAB_000bc280:
      uVar12 = local_30;
      if (local_30 != 5) {
        if ((int)local_30 < 6) {
          if (local_30 != 2) {
            if (local_30 == 3) {
              psVar3 = (size_t *)i2c_ASN1_BIT_STRING((ASN1_BIT_STRING *)*piVar5,(uchar **)0x0);
              goto LAB_000bc15e;
            }
            if (local_30 != 1) goto LAB_000bc316;
            pAVar4 = (ASN1_BIT_STRING *)*piVar5;
            if (pAVar4 == (ASN1_BIT_STRING *)0xffffffff) {
              return (size_t *)0x0;
            }
            if (sVar7 != 0xfffffffc) goto LAB_000bc2dc;
            goto LAB_000bc3ae;
          }
LAB_000bc330:
          psVar3 = (size_t *)i2c_ASN1_INTEGER((ASN1_INTEGER *)*piVar5,(uchar **)0x0);
          goto LAB_000bc15e;
        }
        if (local_30 == 10) goto LAB_000bc330;
        if ((int)local_30 < 0xb) {
          if (local_30 == 6) {
            psVar3 = (size_t *)((ASN1_BIT_STRING *)*piVar5)->flags;
            goto LAB_000bc15e;
          }
        }
        else if ((local_30 == 0x102) || (local_30 == 0x10a)) goto LAB_000bc330;
LAB_000bc316:
        if ((*(int *)(param_3 + 0x14) != 0x800) ||
           (-1 < ((ASN1_BIT_STRING *)*piVar5)->flags << 0x1b)) {
          psVar3 = (size_t *)((ASN1_BIT_STRING *)*piVar5)->length;
          goto LAB_000bc15e;
        }
        uVar13 = local_30 - 0x10;
        constructed = 2;
        bVar15 = 0xfffffffc < local_30;
        bVar14 = local_30 == 0xfffffffd;
        if (!bVar14) {
          bVar15 = uVar13 != 0;
        }
        bVar1 = uVar13 == 1;
        psVar3 = (size_t *)0x0;
        if (!bVar15 || (bVar14 || bVar1)) {
          uVar13 = 1;
        }
        if (bVar15 && (!bVar14 && !bVar1)) {
          uVar13 = 0;
        }
        uVar13 = uVar13 ^ 1;
        goto LAB_000bc188;
      }
      uVar13 = 1;
      psVar3 = (size_t *)0x0;
    }
LAB_000bc184:
    constructed = 0;
  }
  else {
    psVar3 = (size_t *)(*pcVar11)(param_1,0,&local_30,param_3);
LAB_000bc15e:
    uVar13 = local_30 - 0x10;
    bVar15 = 0xfffffffc < local_30;
    bVar14 = local_30 == 0xfffffffd;
    if (!bVar14) {
      bVar15 = uVar13 != 0;
    }
    bVar1 = uVar13 == 1;
    if (!bVar15 || (bVar14 || bVar1)) {
      uVar13 = 1;
    }
    if (bVar15 && (!bVar14 && !bVar1)) {
      uVar13 = 0;
    }
    uVar13 = uVar13 ^ 1;
    if (psVar3 == (size_t *)0xffffffff) {
      return (size_t *)0x0;
    }
    uVar12 = local_30;
    if (psVar3 != (size_t *)0xfffffffe) goto LAB_000bc184;
    constructed = 2;
    psVar3 = (size_t *)0x0;
  }
LAB_000bc188:
  if (param_4 == 0xffffffff) {
    param_4 = uVar12;
  }
  if (param_2 == (uchar **)0x0) goto joined_r0x000bc24a;
  if (uVar13 != 0) {
    ASN1_put_object(param_2,constructed,(int)psVar3,param_4,param_5);
  }
  local_2c[0] = (uchar ********)*param_2;
  if ((*(int *)(param_3 + 0x10) == 0) ||
     (pcVar11 = *(code **)(*(int *)(param_3 + 0x10) + 0x18), pcVar11 == (code *)0x0)) {
    if (*param_3 == '\0') {
      iVar8 = *(int *)(param_3 + 4);
      if (iVar8 == 1) goto LAB_000bc1fc;
      pAVar4 = (ASN1_BIT_STRING *)*param_1;
      if (pAVar4 != (ASN1_BIT_STRING *)0x0) goto LAB_000bc1f4;
    }
    else {
      pAVar4 = (ASN1_BIT_STRING *)*param_1;
      if (pAVar4 != (ASN1_BIT_STRING *)0x0) {
        if (*param_3 == '\x05') {
          local_30 = pAVar4->type;
        }
        else {
          iVar8 = *(int *)(param_3 + 4);
LAB_000bc1f4:
          if (iVar8 == -4) {
            param_1 = &pAVar4->type;
            local_30 = pAVar4->length;
          }
        }
LAB_000bc1fc:
        if (local_30 == 5) {
          __n = (uchar ********)0x0;
          ppppppppuVar6 = __n;
LAB_000bc228:
          ppppppppuVar2 = __n;
          if (local_2c[0] == (uchar ********)0x0) goto joined_r0x000bc23c;
        }
        else {
          if (5 < (int)local_30) {
            if (local_30 == 10) goto LAB_000bc35c;
            if ((int)local_30 < 0xb) {
              if (local_30 == 6) {
                __n = (uchar ********)((size_t *)*param_1)[3];
                ppppppppuVar6 = (uchar ********)((size_t *)*param_1)[4];
                goto LAB_000bc228;
              }
            }
            else if ((local_30 == 0x102) || (local_30 == 0x10a)) goto LAB_000bc35c;
LAB_000bc216:
            ppuVar9 = (uchar **)*param_1;
            if ((*(int *)(param_3 + 0x14) == 0x800) && ((int)ppuVar9[3] << 0x1b < 0)) {
              if (local_2c[0] != (uchar ********)0x0) {
                ppuVar9[2] = (uchar *)local_2c[0];
                *ppuVar9 = (uchar *)0x0;
              }
              goto joined_r0x000bc23c;
            }
            __n = (uchar ********)*ppuVar9;
            ppppppppuVar6 = (uchar ********)ppuVar9[2];
            goto LAB_000bc228;
          }
          if (local_30 == 2) {
LAB_000bc35c:
            ppppppppuVar6 = local_2c[0];
            if (local_2c[0] != (uchar ********)0x0) {
              ppppppppuVar6 = (uchar ********)local_2c;
            }
            i2c_ASN1_INTEGER((ASN1_INTEGER *)*param_1,(uchar **)ppppppppuVar6);
            goto joined_r0x000bc23c;
          }
          if (local_30 == 3) {
            ppppppppuVar6 = local_2c[0];
            if (local_2c[0] != (uchar ********)0x0) {
              ppppppppuVar6 = (uchar ********)local_2c;
            }
            i2c_ASN1_BIT_STRING((ASN1_BIT_STRING *)*param_1,(uchar **)ppppppppuVar6);
            goto joined_r0x000bc23c;
          }
          if (local_30 != 1) goto LAB_000bc216;
          psVar10 = (size_t *)*param_1;
          if (psVar10 == (size_t *)0xffffffff) goto joined_r0x000bc23c;
          if (*(int *)(param_3 + 4) != -4) {
            if (psVar10 == (size_t *)0x0) {
              if (*(int *)(param_3 + 0x14) != 0) goto LAB_000bc386;
            }
            else if (*(int *)(param_3 + 0x14) < 1) goto LAB_000bc386;
            goto joined_r0x000bc23c;
          }
LAB_000bc386:
          local_38 = SUB41(psVar10,0);
          __n = (uchar ********)0x1;
          ppppppppuVar6 = (uchar ********)&local_38;
          ppppppppuVar2 = local_2c[0];
        }
        if (ppppppppuVar2 != (uchar ********)0x0) {
          memcpy(local_2c[0],ppppppppuVar6,(size_t)__n);
        }
      }
    }
  }
  else {
    (*pcVar11)(param_1,local_2c[0],&local_30,param_3);
  }
joined_r0x000bc23c:
  if (constructed == 0) {
    *param_2 = *param_2 + (int)psVar3;
  }
  else {
    ASN1_put_eoc(param_2);
  }
joined_r0x000bc24a:
  if (uVar13 == 0) {
    return psVar3;
  }
  psVar3 = (size_t *)ASN1_object_size(constructed,(int)psVar3,param_4);
  return psVar3;
}

