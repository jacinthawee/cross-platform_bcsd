
int i2d_SSL_SESSION(SSL_SESSION *in,uchar **pp)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  SSL_SESSION *pSVar8;
  uint length;
  undefined4 uVar9;
  uchar *puVar10;
  int local_1a4;
  int local_198;
  int local_190;
  X509 *local_18c;
  int local_188;
  int local_180;
  int local_17c;
  uchar local_178 [4];
  byte *local_174;
  ASN1_INTEGER local_170;
  ASN1_INTEGER local_160;
  ASN1_OCTET_STRING local_150;
  ASN1_OCTET_STRING local_140;
  ASN1_OCTET_STRING local_130;
  ASN1_OCTET_STRING local_120;
  ASN1_OCTET_STRING local_110;
  ASN1_OCTET_STRING local_100;
  ASN1_INTEGER local_f0;
  ASN1_INTEGER local_e0;
  ASN1_INTEGER local_d0;
  ASN1_OCTET_STRING local_c0;
  ASN1_INTEGER local_b0;
  ASN1_OCTET_STRING local_a0;
  ASN1_OCTET_STRING local_90;
  ASN1_OCTET_STRING local_80;
  ASN1_OCTET_STRING local_70;
  uchar local_60;
  uchar local_5f;
  uchar local_5e;
  uchar auStack_5c [8];
  uchar auStack_54 [8];
  uchar auStack_4c [8];
  uchar auStack_44 [8];
  uchar auStack_3c [8];
  uchar auStack_34 [8];
  int local_2c;
  
  local_2c = __TMC_END__;
  pSVar8 = in;
  if ((in != (SSL_SESSION *)0x0) &&
     ((*(int *)(in->krb5_client_princ + 0x24) != 0 ||
      (pSVar8 = *(SSL_SESSION **)(in->krb5_client_princ + 0x28), pSVar8 != (SSL_SESSION *)0x0)))) {
    local_170.data = auStack_5c;
    local_170.length = 8;
    local_170.type = 2;
    ASN1_INTEGER_set(&local_170,1);
    local_160.data = auStack_54;
    local_160.length = 8;
    local_160.type = 2;
    ASN1_INTEGER_set(&local_160,in->ssl_version);
    local_150.data = &local_60;
    local_150.type = 4;
    if (*(int *)(in->krb5_client_princ + 0x24) == 0) {
      uVar9 = *(undefined4 *)(in->krb5_client_princ + 0x28);
    }
    else {
      uVar9 = *(undefined4 *)(*(int *)(in->krb5_client_princ + 0x24) + 8);
    }
    local_5f = (uchar)((uint)uVar9 >> 8);
    if (in->ssl_version == 2) {
      local_150.length = 3;
      local_60 = (uchar)((uint)uVar9 >> 0x10);
      local_5e = (uchar)uVar9;
    }
    else {
      local_150.length = 2;
      local_60 = local_5f;
      local_5f = (uchar)uVar9;
    }
    if (*(int *)(in->krb5_client_princ + 0x20) != 0) {
      local_140.data = local_178;
      local_178[0] = (uchar)*(int *)(in->krb5_client_princ + 0x20);
      local_140.length = 1;
      local_140.type = 4;
    }
    local_120.length = in->session_id_length;
    local_130.length = in->master_key_length;
    local_130.data = in->master_key;
    local_120.data = in->session_id;
    local_110.data = in->sid_ctx;
    local_110.length = in->sid_ctx_length;
    local_100.data = in->key_arg;
    local_130.type = 4;
    local_100.length = in->key_arg_length;
    local_120.type = 4;
    local_110.type = 4;
    local_100.type = 4;
    if (*(long *)(in->krb5_client_princ + 0x1c) != 0) {
      local_f0.length = 8;
      local_f0.type = 2;
      local_f0.data = auStack_4c;
      ASN1_INTEGER_set(&local_f0,*(long *)(in->krb5_client_princ + 0x1c));
    }
    if (*(long *)(in->krb5_client_princ + 0x18) != 0) {
      local_e0.length = 8;
      local_e0.type = 2;
      local_e0.data = auStack_44;
      ASN1_INTEGER_set(&local_e0,*(long *)(in->krb5_client_princ + 0x18));
    }
    if (*(long *)(in->krb5_client_princ + 0x10) != 0) {
      local_d0.length = 8;
      local_d0.type = 2;
      local_d0.data = auStack_3c;
      ASN1_INTEGER_set(&local_d0,*(long *)(in->krb5_client_princ + 0x10));
    }
    puVar10 = *(uchar **)(in->krb5_client_princ + 0x40);
    if (puVar10 != (uchar *)0x0) {
      local_c0.length = strlen((char *)puVar10);
      local_c0.type = 4;
      local_c0.data = puVar10;
    }
    if (*(uchar **)(in->krb5_client_princ + 0x54) != (uchar *)0x0) {
      local_a0.length = *(int *)(in->krb5_client_princ + 0x58);
      local_a0.type = 4;
      local_a0.data = *(uchar **)(in->krb5_client_princ + 0x54);
    }
    if (0 < *(long *)(in->krb5_client_princ + 0x5c)) {
      local_b0.length = 8;
      local_b0.type = 2;
      local_b0.data = auStack_34;
      ASN1_INTEGER_set(&local_b0,*(long *)(in->krb5_client_princ + 0x5c));
    }
    puVar10 = (uchar *)in->krb5_client_princ_len;
    if (puVar10 != (uchar *)0x0) {
      local_90.length = strlen((char *)puVar10);
      local_90.type = 4;
      local_90.data = puVar10;
    }
    puVar10 = *(uchar **)in->krb5_client_princ;
    if (puVar10 != (uchar *)0x0) {
      local_80.length = strlen((char *)puVar10);
      local_80.type = 4;
      local_80.data = puVar10;
    }
    puVar10 = *(uchar **)(in->krb5_client_princ + 0x60);
    if (puVar10 != (uchar *)0x0) {
      local_70.length = strlen((char *)puVar10);
      local_70.type = 4;
      local_70.data = puVar10;
    }
    iVar2 = i2d_ASN1_INTEGER(&local_170,(uchar **)0x0);
    iVar3 = i2d_ASN1_INTEGER(&local_160,(uchar **)0x0);
    iVar4 = i2d_ASN1_OCTET_STRING(&local_150,(uchar **)0x0);
    iVar5 = i2d_ASN1_OCTET_STRING(&local_120,(uchar **)0x0);
    iVar6 = i2d_ASN1_OCTET_STRING(&local_130,(uchar **)0x0);
    iVar6 = iVar2 + iVar3 + iVar4 + iVar5 + iVar6;
    if (in->key_arg_length != 0) {
      iVar2 = i2d_ASN1_OCTET_STRING(&local_100,(uchar **)0x0);
      iVar6 = iVar6 + iVar2;
    }
    local_188 = *(int *)(in->krb5_client_princ + 0x1c);
    if (local_188 != 0) {
      local_188 = i2d_ASN1_INTEGER(&local_f0,(uchar **)0x0);
      iVar2 = ASN1_object_size(1,local_188,1);
      iVar6 = iVar6 + iVar2;
    }
    iVar2 = *(int *)(in->krb5_client_princ + 0x18);
    if (iVar2 == 0) {
      local_18c = *(X509 **)(in->krb5_client_princ + 0xc);
    }
    else {
      iVar2 = i2d_ASN1_INTEGER(&local_e0,(uchar **)0x0);
      iVar3 = ASN1_object_size(1,iVar2,2);
      iVar6 = iVar6 + iVar3;
      local_18c = *(X509 **)(in->krb5_client_princ + 0xc);
    }
    if (local_18c != (X509 *)0x0) {
      local_18c = (X509 *)i2d_X509(local_18c,(uchar **)0x0);
      iVar3 = ASN1_object_size(1,(int)local_18c,3);
      iVar6 = iVar6 + iVar3;
    }
    iVar4 = i2d_ASN1_OCTET_STRING(&local_110,(uchar **)0x0);
    iVar3 = ASN1_object_size(1,iVar4,4);
    local_180 = *(int *)(in->krb5_client_princ + 0x10);
    iVar3 = iVar3 + iVar6;
    if (local_180 != 0) {
      local_180 = i2d_ASN1_INTEGER(&local_d0,(uchar **)0x0);
      iVar6 = ASN1_object_size(1,local_180,5);
      iVar3 = iVar3 + iVar6;
    }
    if (*(int *)(in->krb5_client_princ + 0x5c) < 1) {
      local_190 = 0;
    }
    else {
      local_190 = i2d_ASN1_INTEGER(&local_b0,(uchar **)0x0);
      iVar6 = ASN1_object_size(1,local_190,9);
      iVar3 = iVar3 + iVar6;
    }
    local_198 = *(int *)(in->krb5_client_princ + 0x54);
    if (local_198 != 0) {
      local_198 = i2d_ASN1_OCTET_STRING(&local_a0,(uchar **)0x0);
      iVar6 = ASN1_object_size(1,local_198,10);
      iVar3 = iVar3 + iVar6;
    }
    iVar6 = *(int *)(in->krb5_client_princ + 0x40);
    if (iVar6 != 0) {
      iVar6 = i2d_ASN1_OCTET_STRING(&local_c0,(uchar **)0x0);
      iVar5 = ASN1_object_size(1,iVar6,6);
      iVar3 = iVar3 + iVar5;
    }
    local_17c = *(int *)(in->krb5_client_princ + 0x20);
    if (local_17c != 0) {
      local_17c = i2d_ASN1_OCTET_STRING(&local_140,(uchar **)0x0);
      iVar5 = ASN1_object_size(1,local_17c,0xb);
      iVar3 = iVar3 + iVar5;
    }
    length = in->krb5_client_princ_len;
    if (length != 0) {
      length = i2d_ASN1_OCTET_STRING(&local_90,(uchar **)0x0);
      iVar5 = ASN1_object_size(1,length,7);
      iVar3 = iVar3 + iVar5;
    }
    iVar5 = *(int *)in->krb5_client_princ;
    if (iVar5 == 0) {
      local_1a4 = *(int *)(in->krb5_client_princ + 0x60);
    }
    else {
      iVar5 = i2d_ASN1_OCTET_STRING(&local_80,(uchar **)0x0);
      iVar7 = ASN1_object_size(1,iVar5,8);
      local_1a4 = *(int *)(in->krb5_client_princ + 0x60);
      iVar3 = iVar3 + iVar7;
    }
    if (local_1a4 != 0) {
      local_1a4 = i2d_ASN1_OCTET_STRING(&local_70,(uchar **)0x0);
      iVar7 = ASN1_object_size(1,local_1a4,0xc);
      iVar3 = iVar3 + iVar7;
    }
    pSVar8 = (SSL_SESSION *)ASN1_object_size(1,iVar3,0x10);
    if (pp != (uchar **)0x0) {
      local_174 = *pp;
      ASN1_put_object(&local_174,1,iVar3,0x10,0);
      i2d_ASN1_INTEGER(&local_170,&local_174);
      i2d_ASN1_INTEGER(&local_160,&local_174);
      i2d_ASN1_OCTET_STRING(&local_150,&local_174);
      i2d_ASN1_OCTET_STRING(&local_120,&local_174);
      i2d_ASN1_OCTET_STRING(&local_130,&local_174);
      pbVar1 = local_174;
      if (in->key_arg_length != 0) {
        i2d_ASN1_OCTET_STRING(&local_100,&local_174);
        *pbVar1 = *pbVar1 & 0x20 | 0x80;
      }
      if (*(int *)(in->krb5_client_princ + 0x1c) != 0) {
        ASN1_put_object(&local_174,1,local_188,1,0x80);
        i2d_ASN1_INTEGER(&local_f0,&local_174);
      }
      if (*(int *)(in->krb5_client_princ + 0x18) != 0) {
        ASN1_put_object(&local_174,1,iVar2,2,0x80);
        i2d_ASN1_INTEGER(&local_e0,&local_174);
      }
      if (*(int *)(in->krb5_client_princ + 0xc) != 0) {
        ASN1_put_object(&local_174,1,(int)local_18c,3,0x80);
        i2d_X509(*(X509 **)(in->krb5_client_princ + 0xc),&local_174);
      }
      ASN1_put_object(&local_174,1,iVar4,4,0x80);
      i2d_ASN1_OCTET_STRING(&local_110,&local_174);
      if (*(int *)(in->krb5_client_princ + 0x10) != 0) {
        ASN1_put_object(&local_174,1,local_180,5,0x80);
        i2d_ASN1_INTEGER(&local_d0,&local_174);
      }
      if (*(int *)(in->krb5_client_princ + 0x40) != 0) {
        ASN1_put_object(&local_174,1,iVar6,6,0x80);
        i2d_ASN1_OCTET_STRING(&local_c0,&local_174);
      }
      if (in->krb5_client_princ_len != 0) {
        ASN1_put_object(&local_174,1,length,7,0x80);
        i2d_ASN1_OCTET_STRING(&local_90,&local_174);
      }
      if (*(int *)in->krb5_client_princ != 0) {
        ASN1_put_object(&local_174,1,iVar5,8,0x80);
        i2d_ASN1_OCTET_STRING(&local_80,&local_174);
      }
      if (0 < *(int *)(in->krb5_client_princ + 0x5c)) {
        ASN1_put_object(&local_174,1,local_190,9,0x80);
        i2d_ASN1_INTEGER(&local_b0,&local_174);
      }
      if (*(int *)(in->krb5_client_princ + 0x54) != 0) {
        ASN1_put_object(&local_174,1,local_198,10,0x80);
        i2d_ASN1_OCTET_STRING(&local_a0,&local_174);
      }
      if (*(int *)(in->krb5_client_princ + 0x20) != 0) {
        ASN1_put_object(&local_174,1,local_17c,0xb,0x80);
        i2d_ASN1_OCTET_STRING(&local_140,&local_174);
      }
      if (*(int *)(in->krb5_client_princ + 0x60) != 0) {
        ASN1_put_object(&local_174,1,local_1a4,0xc,0x80);
        i2d_ASN1_OCTET_STRING(&local_70,&local_174);
      }
      *pp = local_174;
    }
  }
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)pSVar8;
}

