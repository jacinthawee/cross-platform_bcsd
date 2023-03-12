
/* WARNING: Type propagation algorithm not settling */

_STACK * ssl_create_cipher_list(int param_1,_STACK **param_2,_STACK **param_3,char *param_4)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  _STACK *p_Var6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  _func_257 *p_Var14;
  _STACK *p_Var15;
  undefined *puVar16;
  uint uVar17;
  uint uVar18;
  int *piVar19;
  _STACK *p_Var20;
  _STACK *p_Var21;
  int *piVar22;
  uint uVar23;
  _STACK *p_Var24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  _STACK *p_Var28;
  uint uVar29;
  uint uVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  _STACK *p_Var34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  _STACK *p_Var38;
  _STACK *p_Var39;
  undefined *puVar40;
  bool bVar41;
  char *local_4c;
  _STACK *local_38;
  _STACK *local_34;
  int *local_30;
  int *local_2c [2];
  
  piVar7 = (int *)(uint)(param_2 == (_STACK **)0x0 || param_4 == (char *)0x0);
  local_38 = (_STACK *)0x0;
  local_34 = (_STACK *)0x0;
  if (param_2 == (_STACK **)0x0 || param_4 == (char *)0x0) {
    return (_STACK *)0x0;
  }
  if (param_3 == (_STACK **)0x0) {
    return (_STACK *)0x0;
  }
  local_30 = piVar7;
  local_2c[0] = piVar7;
  pEVar1 = EVP_PKEY_asn1_find_str((ENGINE **)&local_30,"gost94",-1);
  if (pEVar1 != (EVP_PKEY_ASN1_METHOD *)0x0) {
    EVP_PKEY_asn1_get0_info((int *)local_2c,piVar7,piVar7,(char **)piVar7,(char **)piVar7,pEVar1);
  }
  if (local_30 != (int *)0x0) {
    ENGINE_finish((ENGINE *)local_30);
  }
  if (local_2c[0] == (int *)0x0) {
    uVar23 = 0x128;
  }
  else {
    uVar23 = 0x28;
  }
  local_30 = (int *)0x0;
  local_2c[0] = (int *)0x0;
  pEVar1 = EVP_PKEY_asn1_find_str((ENGINE **)&local_30,"gost2001",-1);
  if (pEVar1 != (EVP_PKEY_ASN1_METHOD *)0x0) {
    EVP_PKEY_asn1_get0_info((int *)local_2c,(int *)0x0,(int *)0x0,(char **)0x0,(char **)0x0,pEVar1);
  }
  if (local_30 != (int *)0x0) {
    ENGINE_finish((ENGINE *)local_30);
  }
  if (local_2c[0] == (int *)0x0) {
    uVar23 = uVar23 | 0x200;
  }
  bVar41 = (uVar23 & 0x300) != 0x300;
  uVar36 = 0xfffffde9;
  if (bVar41) {
    uVar36 = 0xffffffe9;
  }
  uVar35 = 0x216;
  if (bVar41) {
    uVar35 = 0x16;
  }
  if (ssl_cipher_methods._4_4_ == 0) {
    uVar9 = 2;
  }
  else {
    uVar9 = 0;
  }
  if (ssl_cipher_methods._0_4_ == 0) {
    uVar9 = uVar9 | 1;
  }
  if (ssl_cipher_methods._8_4_ == 0) {
    uVar2 = 4;
  }
  else {
    uVar2 = 0;
  }
  if (ssl_cipher_methods._12_4_ == 0) {
    uVar25 = 8;
  }
  else {
    uVar25 = 0;
  }
  if (ssl_cipher_methods._16_4_ == 0) {
    uVar10 = 0x10;
  }
  else {
    uVar10 = 0;
  }
  if (ssl_cipher_methods._24_4_ == 0) {
    uVar17 = 0x40;
  }
  else {
    uVar17 = 0;
  }
  if (ssl_cipher_methods._28_4_ == 0) {
    uVar3 = 0x80;
  }
  else {
    uVar3 = 0;
  }
  if (ssl_cipher_methods._48_4_ == 0) {
    uVar11 = 0x1000;
  }
  else {
    uVar11 = 0;
  }
  if (ssl_cipher_methods._52_4_ == 0) {
    uVar18 = 0x2000;
  }
  else {
    uVar18 = 0;
  }
  if (ssl_cipher_methods._32_4_ == 0) {
    uVar4 = 0x100;
  }
  else {
    uVar4 = 0;
  }
  if (ssl_cipher_methods._36_4_ == 0) {
    uVar12 = 0x200;
  }
  else {
    uVar12 = 0;
  }
  if (ssl_digest_methods._4_4_ == 0) {
    uVar26 = 2;
  }
  else {
    uVar26 = 0;
  }
  if (ssl_digest_methods._0_4_ == 0) {
    uVar26 = uVar26 | 1;
  }
  if (ssl_digest_methods._16_4_ == 0) {
    uVar29 = 0x10;
  }
  else {
    uVar29 = 0;
  }
  if (ssl_cipher_methods._40_4_ == 0) {
    uVar37 = 0x400;
  }
  else {
    uVar37 = 0;
  }
  if (ssl_digest_methods._20_4_ == 0) {
    uVar27 = 0x20;
  }
  else {
    uVar27 = 0;
  }
  if (ssl_cipher_methods._44_4_ == 0) {
    uVar13 = 0x800;
  }
  else {
    uVar13 = 0;
  }
  if (ssl_digest_methods._8_4_ == 0) {
    uVar30 = 4;
  }
  else {
    uVar30 = 0;
  }
  uVar13 = uVar13 | uVar37 | uVar4 | uVar9 | uVar2 | uVar25 | uVar10 | uVar17 | uVar3 | uVar11 |
                                     uVar18 | uVar12;
  if (ssl_digest_methods._12_4_ == 0) {
    uVar9 = 8;
  }
  else if (DAT_0018e040 == 0) {
    uVar9 = 8;
  }
  else {
    uVar9 = 0;
  }
  uVar9 = uVar9 | uVar26 | uVar29 | uVar27 | uVar30;
  iVar5 = (**(code **)(param_1 + 0x54))();
  p_Var6 = (_STACK *)CRYPTO_malloc(iVar5 * 0x14,"ssl_ciph.c",0x56a);
  if (p_Var6 == (_STACK *)0x0) {
    ERR_put_error(0x14,0xa6,0x41,"ssl_ciph.c",0x56d);
    return (_STACK *)0x0;
  }
  p_Var34 = local_38;
  p_Var20 = local_38;
  p_Var39 = local_34;
  if (0 < iVar5) {
    iVar8 = 0;
    iVar32 = 0;
    do {
      iVar33 = iVar32 + 1;
      piVar7 = (int *)(**(code **)(param_1 + 0x58))(iVar32);
      iVar31 = iVar8;
      if ((((piVar7 != (int *)0x0) && (*piVar7 != 0)) && ((uVar35 & piVar7[3]) == 0)) &&
         (((uVar23 & piVar7[4]) == 0 && ((uVar13 & piVar7[5]) == 0)))) {
        bVar41 = (piVar7[6] & uVar9) == 0;
        if (bVar41) {
          iVar31 = iVar8 + 1;
          p_Var6[iVar8].num = (int)piVar7;
        }
        if (bVar41) {
          p_Var6[iVar8].num_alloc = 0;
        }
        if (bVar41) {
          p_Var6[iVar8].comp = (_func_257 *)0x0;
        }
        if (bVar41) {
          p_Var6[iVar8].data = (char **)0x0;
        }
      }
      iVar8 = iVar31;
      iVar32 = iVar33;
    } while (iVar33 != iVar5);
    p_Var34 = local_38;
    p_Var20 = local_38;
    p_Var39 = local_34;
    if (iVar31 != 0) {
      p_Var6->comp = (_func_257 *)0x0;
      local_34 = p_Var6;
      if (iVar31 != 1) {
        if (iVar31 != 2) {
          piVar7 = (int *)(iVar31 + -1);
        }
        p_Var6->num_alloc = (int)(p_Var6 + 1);
        if (iVar31 != 2) {
          piVar19 = (int *)0x1;
          p_Var34 = p_Var6 + 2;
          do {
            piVar19 = (int *)((int)piVar19 + 1);
            p_Var34[-1].num_alloc = (int)p_Var34;
            p_Var34[-1].comp = (_func_257 *)(p_Var34 + -2);
            p_Var34 = p_Var34 + 1;
          } while (piVar19 != piVar7);
        }
        p_Var6[iVar31 + -1].comp = (_func_257 *)(p_Var6 + iVar31 + -2);
        local_34 = p_Var6 + iVar31 + -1;
      }
      local_34->num_alloc = 0;
      local_38 = p_Var6;
      p_Var34 = p_Var6;
      p_Var20 = p_Var6;
      p_Var39 = local_34;
    }
  }
  while (p_Var28 = p_Var20, p_Var38 = local_34, p_Var20 = local_38, p_Var24 = local_34,
        p_Var34 != (_STACK *)0x0 && p_Var34 != p_Var39) {
    p_Var20 = (_STACK *)p_Var28->num_alloc;
    p_Var34 = p_Var28;
    if ((*(int *)(p_Var28->num + 0xc) << 0x18 < 0) && (p_Var28->data == (char **)0x0)) {
      if (p_Var28 != local_34) {
        p_Var14 = p_Var28->comp;
        if (local_38 == p_Var28) {
          local_38 = p_Var20;
        }
        p_Var38 = p_Var20;
        if (p_Var14 != (_func_257 *)0x0) {
          *(_STACK **)(p_Var14 + 0xc) = p_Var20;
          p_Var38 = (_STACK *)p_Var28->num_alloc;
        }
        if (p_Var38 != (_STACK *)0x0) {
          p_Var38->comp = p_Var14;
        }
        local_34->num_alloc = (int)p_Var28;
        p_Var28->comp = (_func_257 *)local_34;
        p_Var28->num_alloc = 0;
        local_34 = p_Var28;
      }
      p_Var28->data = (char **)0x1;
    }
  }
  while (p_Var28 = p_Var38, p_Var34 = p_Var20, p_Var39 = local_34, p_Var38 = p_Var20,
        p_Var24 != (_STACK *)0x0 && local_38 != p_Var24) {
    p_Var38 = (_STACK *)p_Var28->comp;
    p_Var24 = p_Var28;
    if ((*(int *)(p_Var28->num + 0xc) << 0x18 < 0) && (p_Var28->data != (char **)0x0)) {
      if (p_Var28 != p_Var20) {
        iVar8 = p_Var28->num_alloc;
        if (p_Var28 == local_34) {
          local_34 = p_Var38;
        }
        p_Var34 = p_Var38;
        if (iVar8 != 0) {
          *(_STACK **)(iVar8 + 0x10) = p_Var38;
          p_Var34 = (_STACK *)p_Var28->comp;
        }
        if (p_Var34 != (_STACK *)0x0) {
          p_Var34->num_alloc = iVar8;
        }
        p_Var20->comp = (_func_257 *)p_Var28;
        p_Var28->num_alloc = (int)p_Var20;
        p_Var28->comp = (_func_257 *)0x0;
        p_Var20 = p_Var28;
      }
      p_Var28->data = (char **)0x0;
    }
  }
  while (p_Var21 = p_Var38, p_Var38 = p_Var20, p_Var24 = p_Var39, p_Var28 = p_Var20,
        p_Var34 != (_STACK *)0x0 && p_Var34 != local_34) {
    p_Var38 = (_STACK *)p_Var21->num_alloc;
    p_Var34 = p_Var21;
    if (((*(uint *)(p_Var21->num + 0x14) & 0x30c0) != 0) && (p_Var21->data == (char **)0x0)) {
      if (p_Var21 != p_Var39) {
        p_Var14 = p_Var21->comp;
        if (p_Var21 == p_Var20) {
          p_Var20 = p_Var38;
        }
        p_Var24 = p_Var38;
        if (p_Var14 != (_func_257 *)0x0) {
          *(_STACK **)(p_Var14 + 0xc) = p_Var38;
          p_Var24 = (_STACK *)p_Var21->num_alloc;
        }
        if (p_Var24 != (_STACK *)0x0) {
          p_Var24->comp = p_Var14;
        }
        p_Var39->num_alloc = (int)p_Var21;
        p_Var21->comp = (_func_257 *)p_Var39;
        p_Var21->num_alloc = 0;
        p_Var39 = p_Var21;
      }
      p_Var21->data = (char **)0x1;
    }
  }
  while (p_Var15 = p_Var28, p_Var34 = p_Var20, p_Var28 = p_Var24, p_Var21 = p_Var20,
        p_Var38 != (_STACK *)0x0 && p_Var38 != p_Var39) {
    p_Var28 = (_STACK *)p_Var15->num_alloc;
    p_Var38 = p_Var15;
    if (p_Var15->data == (char **)0x0) {
      if (p_Var15 != p_Var24) {
        p_Var14 = p_Var15->comp;
        if (p_Var20 == p_Var15) {
          p_Var20 = p_Var28;
        }
        p_Var34 = p_Var28;
        if (p_Var14 != (_func_257 *)0x0) {
          *(_STACK **)(p_Var14 + 0xc) = p_Var28;
          p_Var34 = (_STACK *)p_Var15->num_alloc;
        }
        if (p_Var34 != (_STACK *)0x0) {
          p_Var34->comp = p_Var14;
        }
        p_Var24->num_alloc = (int)p_Var15;
        p_Var15->comp = (_func_257 *)p_Var24;
        p_Var15->num_alloc = 0;
        p_Var24 = p_Var15;
      }
      p_Var15->data = (char **)0x1;
    }
  }
  while (p_Var15 = p_Var34, p_Var34 = p_Var20, p_Var39 = p_Var28, p_Var38 = p_Var20,
        p_Var21 != (_STACK *)0x0 && p_Var21 != p_Var24) {
    p_Var34 = (_STACK *)p_Var15->num_alloc;
    p_Var21 = p_Var15;
    if (((*(int *)(p_Var15->num + 0x18) << 0x1f < 0) && (p_Var15->data != (char **)0x0)) &&
       (p_Var15 != p_Var28)) {
      p_Var14 = p_Var15->comp;
      if (p_Var20 == p_Var15) {
        p_Var20 = p_Var34;
      }
      p_Var39 = p_Var34;
      if (p_Var14 != (_func_257 *)0x0) {
        *(_STACK **)(p_Var14 + 0xc) = p_Var34;
        p_Var39 = (_STACK *)p_Var15->num_alloc;
      }
      if (p_Var39 != (_STACK *)0x0) {
        p_Var39->comp = p_Var14;
      }
      p_Var28->num_alloc = (int)p_Var15;
      p_Var15->comp = (_func_257 *)p_Var28;
      p_Var15->num_alloc = 0;
      p_Var28 = p_Var15;
    }
  }
  while (p_Var15 = p_Var34, p_Var34 = p_Var20, p_Var24 = p_Var39, p_Var21 = p_Var20,
        p_Var38 != (_STACK *)0x0 && p_Var38 != p_Var28) {
    p_Var34 = (_STACK *)p_Var15->num_alloc;
    p_Var38 = p_Var15;
    if (((*(int *)(p_Var15->num + 0x10) << 0x1d < 0) && (p_Var15->data != (char **)0x0)) &&
       (p_Var15 != p_Var39)) {
      p_Var14 = p_Var15->comp;
      if (p_Var20 == p_Var15) {
        p_Var20 = p_Var34;
      }
      p_Var24 = p_Var34;
      if (p_Var14 != (_func_257 *)0x0) {
        *(_STACK **)(p_Var14 + 0xc) = p_Var34;
        p_Var24 = (_STACK *)p_Var15->num_alloc;
      }
      if (p_Var24 != (_STACK *)0x0) {
        p_Var24->comp = p_Var14;
      }
      p_Var39->num_alloc = (int)p_Var15;
      p_Var15->comp = (_func_257 *)p_Var39;
      p_Var15->num_alloc = 0;
      p_Var39 = p_Var15;
    }
  }
  while (p_Var15 = p_Var34, p_Var34 = p_Var20, p_Var38 = p_Var24, p_Var28 = p_Var20,
        p_Var21 != (_STACK *)0x0 && p_Var39 != p_Var21) {
    p_Var34 = (_STACK *)p_Var15->num_alloc;
    p_Var21 = p_Var15;
    if (((*(int *)(p_Var15->num + 0x10) << 0x1b < 0) && (p_Var15->data != (char **)0x0)) &&
       (p_Var15 != p_Var24)) {
      p_Var14 = p_Var15->comp;
      if (p_Var20 == p_Var15) {
        p_Var20 = p_Var34;
      }
      p_Var38 = p_Var34;
      if (p_Var14 != (_func_257 *)0x0) {
        *(_STACK **)(p_Var14 + 0xc) = p_Var34;
        p_Var38 = (_STACK *)p_Var15->num_alloc;
      }
      if (p_Var38 != (_STACK *)0x0) {
        p_Var38->comp = p_Var14;
      }
      p_Var24->num_alloc = (int)p_Var15;
      p_Var15->comp = (_func_257 *)p_Var24;
      p_Var15->num_alloc = 0;
      p_Var24 = p_Var15;
    }
  }
  while (p_Var15 = p_Var34, p_Var34 = p_Var20, p_Var39 = p_Var38, p_Var21 = p_Var20,
        p_Var28 != (_STACK *)0x0 && p_Var24 != p_Var28) {
    p_Var34 = (_STACK *)p_Var15->num_alloc;
    p_Var28 = p_Var15;
    if (((*(int *)(p_Var15->num + 0xc) << 0x1f < 0) && (p_Var15->data != (char **)0x0)) &&
       (p_Var38 != p_Var15)) {
      p_Var14 = p_Var15->comp;
      if (p_Var20 == p_Var15) {
        p_Var20 = p_Var34;
      }
      p_Var39 = p_Var34;
      if (p_Var14 != (_func_257 *)0x0) {
        *(_STACK **)(p_Var14 + 0xc) = p_Var34;
        p_Var39 = (_STACK *)p_Var15->num_alloc;
      }
      if (p_Var39 != (_STACK *)0x0) {
        p_Var39->comp = p_Var14;
      }
      p_Var38->num_alloc = (int)p_Var15;
      p_Var15->comp = (_func_257 *)p_Var38;
      p_Var15->num_alloc = 0;
      p_Var38 = p_Var15;
    }
  }
  while (p_Var15 = p_Var34, p_Var34 = p_Var20, p_Var24 = p_Var39, p_Var28 = p_Var20,
        p_Var21 != (_STACK *)0x0 && p_Var38 != p_Var21) {
    p_Var34 = (_STACK *)p_Var15->num_alloc;
    p_Var21 = p_Var15;
    if (((*(int *)(p_Var15->num + 0xc) << 0x17 < 0) && (p_Var15->data != (char **)0x0)) &&
       (p_Var39 != p_Var15)) {
      p_Var14 = p_Var15->comp;
      if (p_Var20 == p_Var15) {
        p_Var20 = p_Var34;
      }
      p_Var24 = p_Var34;
      if (p_Var14 != (_func_257 *)0x0) {
        *(_STACK **)(p_Var14 + 0xc) = p_Var34;
        p_Var24 = (_STACK *)p_Var15->num_alloc;
      }
      if (p_Var24 != (_STACK *)0x0) {
        p_Var24->comp = p_Var14;
      }
      p_Var39->num_alloc = (int)p_Var15;
      p_Var15->comp = (_func_257 *)p_Var39;
      p_Var15->num_alloc = 0;
      p_Var39 = p_Var15;
    }
  }
  while (p_Var21 = p_Var34, p_Var34 = p_Var20, local_34 = p_Var24, p_Var38 = p_Var20,
        p_Var28 != (_STACK *)0x0 && p_Var39 != p_Var28) {
    p_Var34 = (_STACK *)p_Var21->num_alloc;
    p_Var28 = p_Var21;
    if (((*(int *)(p_Var21->num + 0xc) << 0x1b < 0) && (p_Var21->data != (char **)0x0)) &&
       (p_Var24 != p_Var21)) {
      p_Var14 = p_Var21->comp;
      if (p_Var20 == p_Var21) {
        p_Var20 = p_Var34;
      }
      p_Var38 = p_Var34;
      if (p_Var14 != (_func_257 *)0x0) {
        *(_STACK **)(p_Var14 + 0xc) = p_Var34;
        p_Var38 = (_STACK *)p_Var21->num_alloc;
      }
      if (p_Var38 != (_STACK *)0x0) {
        p_Var38->comp = p_Var14;
      }
      p_Var24->num_alloc = (int)p_Var21;
      p_Var21->comp = (_func_257 *)p_Var24;
      p_Var21->num_alloc = 0;
      p_Var24 = p_Var21;
    }
  }
  while (p_Var39 = p_Var34, p_Var38 != (_STACK *)0x0 && p_Var24 != p_Var38) {
    p_Var34 = (_STACK *)p_Var39->num_alloc;
    p_Var38 = p_Var39;
    if (((*(int *)(p_Var39->num + 0x14) << 0x1d < 0) && (p_Var39->data != (char **)0x0)) &&
       (local_34 != p_Var39)) {
      p_Var14 = p_Var39->comp;
      if (p_Var20 == p_Var39) {
        p_Var20 = p_Var34;
      }
      p_Var28 = p_Var34;
      if (p_Var14 != (_func_257 *)0x0) {
        *(_STACK **)(p_Var14 + 0xc) = p_Var34;
        p_Var28 = (_STACK *)p_Var39->num_alloc;
      }
      if (p_Var28 != (_STACK *)0x0) {
        p_Var28->comp = p_Var14;
      }
      local_34->num_alloc = (int)p_Var39;
      p_Var39->comp = (_func_257 *)local_34;
      p_Var39->num_alloc = 0;
      local_34 = p_Var39;
    }
  }
  local_38 = p_Var20;
  iVar8 = ssl_cipher_strength_sort(&local_38,&local_34);
  p_Var34 = local_34;
  p_Var20 = local_34;
  p_Var39 = local_38;
  if (iVar8 != 0) {
    while (p_Var38 = p_Var20, p_Var34 != (_STACK *)0x0 && local_38 != p_Var34) {
      p_Var20 = (_STACK *)p_Var38->comp;
      p_Var34 = p_Var38;
      if (p_Var38->data != (char **)0x0) {
        if (p_Var38 != p_Var39) {
          iVar8 = p_Var38->num_alloc;
          if (local_34 == p_Var38) {
            local_34 = p_Var20;
          }
          p_Var24 = p_Var20;
          if (iVar8 != 0) {
            *(_STACK **)(iVar8 + 0x10) = p_Var20;
            p_Var24 = (_STACK *)p_Var38->comp;
          }
          if (p_Var24 != (_STACK *)0x0) {
            p_Var24->num_alloc = iVar8;
          }
          p_Var39->comp = (_func_257 *)p_Var38;
          p_Var38->num_alloc = (int)p_Var39;
          p_Var38->comp = (_func_257 *)0x0;
          p_Var39 = p_Var38;
        }
        p_Var38->data = (char **)0x0;
      }
    }
    local_38 = p_Var39;
    piVar7 = (int *)CRYPTO_malloc((iVar5 + 0x4a) * 4,"ssl_ciph.c",0x5aa);
    if (piVar7 == (int *)0x0) {
      CRYPTO_free(p_Var6);
      ERR_put_error(0x14,0xa6,0x41,"ssl_ciph.c",0x5ae);
      return (_STACK *)0x0;
    }
    piVar19 = piVar7;
    puVar16 = PTR_cipher_aliases_0006618c;
    for (p_Var34 = local_38; PTR_cipher_aliases_0006618c = puVar16, p_Var34 != (_STACK *)0x0;
        p_Var34 = (_STACK *)p_Var34->num_alloc) {
      *piVar19 = p_Var34->num;
      piVar19 = piVar19 + 1;
      puVar16 = PTR_cipher_aliases_0006618c;
    }
    puVar40 = puVar16 + 0xdb0;
    do {
      piVar22 = piVar19;
      if (((*(uint *)(puVar16 + 0xc) == 0) || ((*(uint *)(puVar16 + 0xc) & uVar36) != 0)) &&
         ((((*(uint *)(puVar16 + 0x10) == 0 || ((*(uint *)(puVar16 + 0x10) & ~uVar23) != 0)) &&
           ((*(uint *)(puVar16 + 0x14) == 0 || ((*(uint *)(puVar16 + 0x14) & ~uVar13) != 0)))) &&
          ((*(uint *)(puVar16 + 0x18) == 0 || ((*(uint *)(puVar16 + 0x18) & ~uVar9) != 0)))))) {
        piVar22 = piVar19 + 1;
        *piVar19 = (int)puVar16;
      }
      puVar16 = puVar16 + 0x30;
      piVar19 = piVar22;
    } while (puVar16 != puVar40);
    *piVar22 = 0;
    iVar5 = strncmp(param_4,"DEFAULT",7);
    local_4c = param_4;
    if (iVar5 == 0) {
      iVar5 = ssl_cipher_process_rulestr("ALL:!aNULL:!eNULL:!SSLv2",&local_38,&local_34,piVar7);
      if (param_4[7] == ':') {
        local_4c = param_4 + 8;
      }
      else {
        local_4c = param_4 + 7;
      }
      if (iVar5 == 0) {
        CRYPTO_free(piVar7);
        goto LAB_0006617e;
      }
    }
    if (*local_4c == '\0') {
      CRYPTO_free(piVar7);
    }
    else {
      iVar5 = ssl_cipher_process_rulestr(local_4c,&local_38,&local_34,piVar7);
      CRYPTO_free(piVar7);
      if (iVar5 == 0) goto LAB_0006617e;
    }
    p_Var20 = sk_new_null();
    p_Var34 = local_38;
    if (p_Var20 == (_STACK *)0x0) {
      CRYPTO_free(p_Var6);
    }
    else {
      for (; p_Var34 != (_STACK *)0x0; p_Var34 = (_STACK *)p_Var34->num_alloc) {
        if (p_Var34->data != (char **)0x0) {
          sk_push(p_Var20,(void *)p_Var34->num);
        }
      }
      CRYPTO_free(p_Var6);
      p_Var6 = sk_dup(p_Var20);
      if (p_Var6 == (_STACK *)0x0) {
        sk_free(p_Var20);
        p_Var20 = p_Var6;
      }
      else {
        if (*param_2 != (_STACK *)0x0) {
          sk_free(*param_2);
        }
        *param_2 = p_Var20;
        if (*param_3 != (_STACK *)0x0) {
          sk_free(*param_3);
        }
        *param_3 = p_Var6;
        sk_set_cmp_func(p_Var6,ssl_cipher_ptr_id_cmp + 1);
        sk_sort(*param_3);
      }
    }
    return p_Var20;
  }
LAB_0006617e:
  CRYPTO_free(p_Var6);
  return (_STACK *)0x0;
}

