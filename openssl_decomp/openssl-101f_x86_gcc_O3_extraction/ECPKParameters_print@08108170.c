
int ECPKParameters_print(BIO *bp,EC_GROUP *x,int off)

{
  BN_CTX *ctx;
  int iVar1;
  EC_METHOD *meth;
  int iVar2;
  EC_POINT *pEVar3;
  char *pcVar4;
  point_conversion_form_t form;
  int iVar5;
  int iVar6;
  uchar *puVar7;
  uint uVar8;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar9;
  BIGNUM *a;
  BIGNUM *p;
  int in_GS_OFFSET;
  uchar *puVar10;
  BIGNUM *local_d8;
  BIGNUM *local_d4;
  uchar *local_d0;
  BIGNUM *local_cc;
  BIGNUM *local_c8;
  int local_c0;
  size_t local_bc;
  int local_b0;
  undefined local_a0;
  undefined local_9f [127];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (x == (EC_GROUP *)0x0) {
    local_cc = (BIGNUM *)0x0;
    local_d4 = (BIGNUM *)0x0;
    a = (BIGNUM *)0x0;
    local_c8 = (BIGNUM *)0x0;
    local_d8 = (BIGNUM *)0x0;
    p = (BIGNUM *)0x0;
    ctx = (BN_CTX *)0x0;
    local_b0 = 0x43;
    local_d0 = (uchar *)0x0;
LAB_08108251:
    iVar1 = 0;
    ERR_put_error(0x10,0x95,local_b0,"eck_prn.c",0x150);
    if (p != (BIGNUM *)0x0) goto LAB_08108274;
  }
  else {
    ctx = BN_CTX_new();
    if (ctx == (BN_CTX *)0x0) {
      local_cc = (BIGNUM *)0x0;
      local_d4 = (BIGNUM *)0x0;
      a = (BIGNUM *)0x0;
      local_c8 = (BIGNUM *)0x0;
      local_d8 = (BIGNUM *)0x0;
      p = (BIGNUM *)0x0;
      local_b0 = 0x41;
      local_d0 = (uchar *)0x0;
      goto LAB_08108251;
    }
    iVar1 = EC_GROUP_get_asn1_flag(x);
    if (iVar1 != 0) {
      iVar1 = BIO_indent(bp,off,0x80);
      if ((iVar1 != 0) && (iVar1 = EC_GROUP_get_curve_name(x), iVar1 != 0)) {
        pcVar4 = OBJ_nid2sn(iVar1);
        iVar1 = BIO_printf(bp,"ASN1 OID: %s",pcVar4);
        if ((0 < iVar1) && (iVar1 = BIO_printf(bp,"\n",pcVar4), 0 < iVar1)) {
          local_d0 = (uchar *)0x0;
          iVar1 = 1;
          goto LAB_081082e0;
        }
      }
      local_cc = (BIGNUM *)0x0;
      local_d4 = (BIGNUM *)0x0;
      a = (BIGNUM *)0x0;
      local_c8 = (BIGNUM *)0x0;
      local_d8 = (BIGNUM *)0x0;
      p = (BIGNUM *)0x0;
      local_b0 = 0x20;
      local_d0 = (uchar *)0x0;
      goto LAB_08108251;
    }
    meth = EC_GROUP_method_of(x);
    iVar1 = EC_METHOD_get_field_type(meth);
    p = BN_new();
    if (p == (BIGNUM *)0x0) {
      local_cc = (BIGNUM *)0x0;
      local_d4 = (BIGNUM *)0x0;
      a = (BIGNUM *)0x0;
      local_c8 = (BIGNUM *)0x0;
      local_d8 = (BIGNUM *)0x0;
      local_b0 = 0x41;
      local_d0 = (uchar *)0x0;
      goto LAB_08108251;
    }
    a = BN_new();
    if (a == (BIGNUM *)0x0) {
      local_cc = (BIGNUM *)0x0;
      local_d4 = (BIGNUM *)0x0;
      local_b0 = 0x41;
      local_c8 = (BIGNUM *)0x0;
      local_d8 = (BIGNUM *)0x0;
      local_d0 = (uchar *)0x0;
      goto LAB_08108251;
    }
    local_d8 = BN_new();
    if (local_d8 == (BIGNUM *)0x0) {
      local_cc = (BIGNUM *)0x0;
      local_d4 = (BIGNUM *)0x0;
      local_b0 = 0x41;
      local_c8 = (BIGNUM *)0x0;
      local_d0 = (uchar *)0x0;
      goto LAB_08108251;
    }
    local_d4 = BN_new();
    if (local_d4 == (BIGNUM *)0x0) {
      local_cc = (BIGNUM *)0x0;
      local_c8 = (BIGNUM *)0x0;
      local_b0 = 0x41;
      local_d0 = (uchar *)0x0;
      goto LAB_08108251;
    }
    local_cc = BN_new();
    if (local_cc == (BIGNUM *)0x0) {
      local_c8 = (BIGNUM *)0x0;
      local_b0 = 0x41;
      local_d0 = (uchar *)0x0;
      goto LAB_08108251;
    }
    if (iVar1 != 0x197) {
      iVar2 = EC_GROUP_get_curve_GFp(x,p,a,local_d8,ctx);
      if (iVar2 != 0) goto LAB_081083ee;
LAB_0810841c:
      local_c8 = (BIGNUM *)0x0;
      local_b0 = 0x10;
      local_d0 = (uchar *)0x0;
      goto LAB_08108251;
    }
    iVar2 = EC_GROUP_get_curve_GF2m(x,p,a,local_d8,ctx);
    if (iVar2 == 0) goto LAB_0810841c;
LAB_081083ee:
    pEVar3 = EC_GROUP_get0_generator(x);
    if (((pEVar3 == (EC_POINT *)0x0) ||
        (iVar2 = EC_GROUP_get_order(x,local_d4,(BN_CTX *)0x0), iVar2 == 0)) ||
       (iVar2 = EC_GROUP_get_cofactor(x,local_cc,(BN_CTX *)0x0), iVar2 == 0)) goto LAB_0810841c;
    form = EC_GROUP_get_point_conversion_form(x);
    local_c8 = EC_POINT_point2bn(x,pEVar3,form,(BIGNUM *)0x0,ctx);
    if (local_c8 == (BIGNUM *)0x0) {
      local_b0 = 0x10;
      local_d0 = (uchar *)0x0;
      goto LAB_08108251;
    }
    iVar5 = BN_num_bits(p);
    iVar2 = iVar5 + 7;
    if (iVar5 + 7 < 0) {
      iVar2 = iVar5 + 0xe;
    }
    iVar6 = BN_num_bits(a);
    iVar5 = iVar6 + 7;
    if (iVar6 + 7 < 0) {
      iVar5 = iVar6 + 0xe;
    }
    uVar8 = iVar2 >> 3;
    if ((uint)(iVar2 >> 3) < (uint)(iVar5 >> 3)) {
      uVar8 = iVar5 >> 3;
    }
    iVar5 = BN_num_bits(local_d8);
    iVar2 = iVar5 + 7;
    if (iVar5 + 7 < 0) {
      iVar2 = iVar5 + 0xe;
    }
    if (uVar8 <= (uint)(iVar2 >> 3)) {
      uVar8 = iVar2 >> 3;
    }
    iVar5 = BN_num_bits(local_c8);
    iVar2 = iVar5 + 7;
    if (iVar5 + 7 < 0) {
      iVar2 = iVar5 + 0xe;
    }
    if (uVar8 <= (uint)(iVar2 >> 3)) {
      uVar8 = iVar2 >> 3;
    }
    iVar5 = BN_num_bits(local_d4);
    iVar2 = iVar5 + 7;
    if (iVar5 + 7 < 0) {
      iVar2 = iVar5 + 0xe;
    }
    if (uVar8 <= (uint)(iVar2 >> 3)) {
      uVar8 = iVar2 >> 3;
    }
    iVar5 = BN_num_bits(local_cc);
    iVar2 = iVar5 + 7;
    if (iVar5 + 7 < 0) {
      iVar2 = iVar5 + 0xe;
    }
    if (uVar8 <= (uint)(iVar2 >> 3)) {
      uVar8 = iVar2 >> 3;
    }
    puVar7 = EC_GROUP_get0_seed(x);
    local_bc = 0;
    if (puVar7 != (uchar *)0x0) {
      local_bc = EC_GROUP_get_seed_len(x);
    }
    local_d0 = (uchar *)CRYPTO_malloc(uVar8 + 10,"eck_prn.c",0x10a);
    if (local_d0 == (uchar *)0x0) {
      local_b0 = 0x41;
      goto LAB_08108251;
    }
    puVar10 = local_d0;
    iVar2 = BIO_indent(bp,off,0x80);
    local_b0 = 0x20;
    if (iVar2 == 0) goto LAB_08108251;
    local_b0 = 0x20;
    pcVar4 = OBJ_nid2sn(iVar1);
    iVar2 = BIO_printf(bp,"Field Type: %s\n",pcVar4,puVar10);
    if (iVar2 < 1) goto LAB_08108251;
    local_c0 = 0x20;
    if (iVar1 == 0x197) {
      iVar1 = EC_GROUP_get_basis_type(x);
      local_b0 = 0x20;
      if (iVar1 != 0) {
        uVar9 = extraout_ECX;
        iVar2 = BIO_indent(bp,off,0x80);
        local_b0 = 0x20;
        if (iVar2 != 0) {
          pcVar4 = OBJ_nid2sn(iVar1);
          iVar1 = BIO_printf(bp,"Basis Type: %s\n",pcVar4,uVar9);
          local_b0 = 0x20;
          if (0 < iVar1) {
            pcVar4 = "Polynomial:";
            goto LAB_0810878c;
          }
        }
      }
      goto LAB_08108251;
    }
    pcVar4 = "Prime:";
LAB_0810878c:
    iVar1 = ASN1_bn_print(bp,pcVar4,p,local_d0,off);
    local_b0 = local_c0;
    if (iVar1 == 0) goto LAB_08108251;
    iVar1 = ASN1_bn_print(bp,"A:   ",a,local_d0,off);
    if ((iVar1 == 0) || (iVar1 = ASN1_bn_print(bp,"B:   ",local_d8,local_d0,off), iVar1 == 0)) {
LAB_081089f8:
      local_b0 = 0x20;
      goto LAB_08108251;
    }
    if (form == POINT_CONVERSION_COMPRESSED) {
      pcVar4 = "Generator (compressed):";
    }
    else if (form == POINT_CONVERSION_UNCOMPRESSED) {
      pcVar4 = "Generator (uncompressed):";
    }
    else {
      pcVar4 = "Generator (hybrid):";
    }
    iVar1 = ASN1_bn_print(bp,pcVar4,local_c8,local_d0,off);
    if (((iVar1 == 0) || (iVar1 = ASN1_bn_print(bp,"Order: ",local_d4,local_d0,off), iVar1 == 0)) ||
       (iVar1 = ASN1_bn_print(bp,"Cofactor: ",local_cc,local_d0,off), iVar1 == 0))
    goto LAB_081089f8;
    if (puVar7 != (uchar *)0x0) {
      uVar9 = extraout_EDX;
      if (off != 0) {
        iVar1 = 0x80;
        if (off < 0x81) {
          iVar1 = off;
        }
        __memset_chk(&local_a0,0x20,iVar1,0x80);
        iVar2 = BIO_write(bp,&local_a0,iVar1);
        uVar9 = extraout_EDX_00;
        off = iVar1;
        if (iVar2 < 1) goto LAB_081089f8;
      }
      iVar1 = BIO_printf(bp,"%s","Seed:",uVar9);
      if (0 < iVar1) {
        uVar8 = 0;
        do {
          if (local_bc == uVar8) {
            iVar1 = BIO_write(bp,&DAT_081f11d3,1);
            if (0 < iVar1) goto LAB_0810898f;
            break;
          }
          if (uVar8 % 0xf == 0) {
            local_a0 = 10;
            __memset_chk(local_9f,0x20,off + 4,0x7f);
            iVar1 = BIO_write(bp,&local_a0,off + 5);
            if (iVar1 < 1) break;
          }
          pcVar4 = "";
          if (local_bc != uVar8 + 1) {
            pcVar4 = ":";
          }
          iVar1 = BIO_printf(bp,"%02x%s",(uint)puVar7[uVar8],pcVar4);
          uVar8 = uVar8 + 1;
        } while (0 < iVar1);
      }
      goto LAB_081089f8;
    }
LAB_0810898f:
    iVar1 = 1;
LAB_08108274:
    BN_free(p);
  }
  if (a != (BIGNUM *)0x0) {
    BN_free(a);
  }
  if (local_d8 != (BIGNUM *)0x0) {
    BN_free(local_d8);
  }
  if (local_c8 != (BIGNUM *)0x0) {
    BN_free(local_c8);
  }
  if (local_d4 != (BIGNUM *)0x0) {
    BN_free(local_d4);
  }
  if (local_cc != (BIGNUM *)0x0) {
    BN_free(local_cc);
  }
LAB_081082e0:
  if (ctx != (BN_CTX *)0x0) {
    BN_CTX_free(ctx);
  }
  if (local_d0 != (uchar *)0x0) {
    CRYPTO_free(local_d0);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

