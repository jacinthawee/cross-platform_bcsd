
_STACK * asn1_template_ex_i2d
                   (_STACK **param_1,uchar **param_2,uint *param_3,uint param_4,uint param_5)

{
  uchar **ppuVar1;
  int iVar2;
  _STACK *p_Var3;
  int iVar4;
  uchar **__base;
  uchar *ptr;
  uchar *puVar5;
  size_t __nmemb;
  _STACK *p_Var6;
  int iVar7;
  uchar **ppuVar8;
  ASN1_ITEM *it;
  int constructed;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  _STACK *local_3c;
  void *local_34;
  ASN1_VALUE *local_30;
  uchar *local_2c [2];
  
  local_44 = *param_3;
  local_50 = local_44 & 0x18;
  if (local_50 == 0) {
    if (param_4 != 0xffffffff) {
      local_50 = param_5 & 0xc0;
    }
    if ((int)(local_44 << 0x14) < 0) {
      if ((param_5 & 0x800) == 0) {
        constructed = 1;
      }
      else {
        constructed = 2;
      }
    }
    else {
      constructed = 1;
    }
  }
  else {
    if (param_4 != 0xffffffff) {
      return (_STACK *)0xffffffff;
    }
    local_50 = local_44 & 0xc0;
    param_4 = param_3[1];
    if ((int)(local_44 << 0x14) < 0) {
      if ((param_5 & 0x800) == 0) {
        constructed = 1;
      }
      else {
        constructed = 2;
      }
    }
    else {
      constructed = 1;
    }
  }
  param_5 = param_5 & 0xffffff3f;
  local_3c = (_STACK *)(local_44 & 6);
  if (local_3c == (_STACK *)0x0) {
    if (-1 < (int)(local_44 << 0x1b)) {
      p_Var6 = (_STACK *)
               ASN1_item_ex_i2d((ASN1_VALUE **)param_1,param_2,(ASN1_ITEM *)param_3[4],param_4,
                                param_5 | local_50);
      return p_Var6;
    }
    iVar4 = ASN1_item_ex_i2d_constprop_0(param_1,param_3[4],param_5);
    if ((iVar4 != 0) &&
       (local_3c = (_STACK *)ASN1_object_size(constructed,iVar4,param_4), param_2 != (uchar **)0x0))
    {
      ASN1_put_object(param_2,constructed,iVar4,param_4,local_50);
      ASN1_item_ex_i2d((ASN1_VALUE **)param_1,param_2,(ASN1_ITEM *)param_3[4],-1,param_5);
      if (constructed == 2) {
        ASN1_put_eoc(param_2);
      }
    }
  }
  else {
    p_Var6 = *param_1;
    local_3c = p_Var6;
    if (p_Var6 != (_STACK *)0x0) {
      local_48 = local_44 & 2;
      if (local_48 != 0) {
        if ((local_44 & 4) == 0) {
          local_48 = 1;
        }
        else {
          local_48 = 2;
        }
      }
      if ((param_4 == 0xffffffff) || ((local_44 & 0x10) != 0)) {
        local_40 = 0;
        if (local_48 == 0) {
          local_4c = 0x10;
        }
        else {
          local_4c = 0x11;
        }
      }
      else {
        local_40 = local_50;
        local_4c = param_4;
      }
      local_44 = local_44 & 0x10;
      iVar7 = 0;
      iVar4 = 0;
      while( true ) {
        iVar2 = sk_num(p_Var6);
        if (iVar2 <= iVar4) break;
        local_34 = sk_value(p_Var6,iVar4);
        iVar2 = ASN1_item_ex_i2d_constprop_0(&local_34,param_3[4],param_5);
        iVar7 = iVar7 + iVar2;
        iVar4 = iVar4 + 1;
      }
      local_3c = (_STACK *)ASN1_object_size(constructed,iVar7,local_4c);
      if (local_44 == 0) {
        if (param_2 == (uchar **)0x0) {
          return local_3c;
        }
      }
      else {
        p_Var3 = (_STACK *)ASN1_object_size(constructed,(int)local_3c,param_4);
        if (param_2 == (uchar **)0x0) {
          return p_Var3;
        }
        ASN1_put_object(param_2,constructed,(int)local_3c,param_4,local_50);
        local_3c = p_Var3;
      }
      ASN1_put_object(param_2,constructed,iVar7,local_4c,local_40);
      it = (ASN1_ITEM *)param_3[4];
      local_2c[0] = (uchar *)0x0;
      if ((local_48 == 0) || (iVar4 = sk_num(p_Var6), iVar4 < 2)) {
        iVar4 = 0;
        while( true ) {
          iVar7 = sk_num(p_Var6);
          if (iVar7 <= iVar4) break;
          local_30 = (ASN1_VALUE *)sk_value(p_Var6,iVar4);
          ASN1_item_ex_i2d(&local_30,param_2,it,-1,param_5);
          iVar4 = iVar4 + 1;
        }
      }
      else {
        iVar4 = sk_num(p_Var6);
        __base = (uchar **)CRYPTO_malloc(iVar4 * 0xc,"tasn_enc.c",0x1c7);
        ptr = (uchar *)CRYPTO_malloc(iVar7,"tasn_enc.c",0x1c8);
        if (__base != (uchar **)0x0 && ptr != (uchar *)0x0) {
          ppuVar8 = __base;
          iVar4 = 0;
          local_2c[0] = ptr;
          while( true ) {
            iVar7 = sk_num(p_Var6);
            if (iVar7 <= iVar4) break;
            local_30 = (ASN1_VALUE *)sk_value(p_Var6,iVar4);
            *ppuVar8 = local_2c[0];
            puVar5 = (uchar *)ASN1_item_ex_i2d(&local_30,local_2c,it,-1,param_5);
            ppuVar8[2] = (uchar *)local_30;
            ppuVar8[1] = puVar5;
            ppuVar8 = ppuVar8 + 3;
            iVar4 = iVar4 + 1;
          }
          __nmemb = sk_num(p_Var6);
          qsort(__base,__nmemb,0xc,der_cmp + 1);
          local_2c[0] = *param_2;
          iVar4 = 0;
          ppuVar8 = __base;
          while( true ) {
            iVar7 = sk_num(p_Var6);
            if (iVar7 <= iVar4) break;
            memcpy(local_2c[0],*ppuVar8,(size_t)ppuVar8[1]);
            local_2c[0] = ppuVar8[1] + (int)local_2c[0];
            iVar4 = iVar4 + 1;
            ppuVar8 = ppuVar8 + 3;
          }
          *param_2 = local_2c[0];
          if (local_48 == 2) {
            ppuVar8 = __base;
            iVar4 = 0;
            while( true ) {
              iVar7 = sk_num(p_Var6);
              if (iVar7 <= iVar4) break;
              ppuVar1 = ppuVar8 + 2;
              ppuVar8 = ppuVar8 + 3;
              sk_set(p_Var6,iVar4,*ppuVar1);
              iVar4 = iVar4 + 1;
            }
          }
          CRYPTO_free(__base);
          CRYPTO_free(ptr);
        }
      }
      if ((constructed != 2) || (ASN1_put_eoc(param_2), local_44 == 0)) {
        return local_3c;
      }
      ASN1_put_eoc(param_2);
    }
  }
  return local_3c;
}

