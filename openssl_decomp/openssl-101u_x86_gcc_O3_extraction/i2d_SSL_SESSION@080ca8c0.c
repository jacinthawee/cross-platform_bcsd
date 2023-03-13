
int i2d_SSL_SESSION(SSL_SESSION *in,uchar **pp)

{
  uchar *puVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int in_GS_OFFSET;
  int local_1a0;
  int local_19c;
  int local_198;
  int local_194;
  int local_190;
  int local_18c;
  int local_180;
  int local_17c;
  int local_178;
  int local_174;
  int local_170;
  uchar local_169;
  byte *local_168;
  ASN1_INTEGER local_164;
  ASN1_INTEGER local_154;
  ASN1_OCTET_STRING local_144;
  ASN1_OCTET_STRING local_134;
  ASN1_OCTET_STRING local_124;
  ASN1_OCTET_STRING local_114;
  ASN1_OCTET_STRING local_104;
  ASN1_OCTET_STRING local_f4;
  ASN1_INTEGER local_e4;
  ASN1_INTEGER local_d4;
  ASN1_INTEGER local_c4;
  ASN1_OCTET_STRING local_b4;
  ASN1_INTEGER local_a4;
  ASN1_OCTET_STRING local_94;
  ASN1_OCTET_STRING local_84;
  ASN1_OCTET_STRING local_74;
  ASN1_OCTET_STRING local_64;
  uchar local_54;
  uchar local_53;
  uchar local_52;
  uchar local_50 [8];
  uchar local_48 [8];
  uchar local_40 [8];
  uchar local_38 [8];
  uchar local_30 [8];
  uchar local_28 [8];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = 0;
  if (in == (SSL_SESSION *)0x0) {
    iVar3 = 0;
  }
  else if ((*(int *)(in->krb5_client_princ + 0x24) != 0) ||
          (*(int *)(in->krb5_client_princ + 0x28) != 0)) {
    local_164.data = local_50;
    local_164.length = 8;
    local_164.type = 2;
    ASN1_INTEGER_set(&local_164,1);
    local_154.data = local_48;
    local_154.length = 8;
    local_154.type = 2;
    ASN1_INTEGER_set(&local_154,in->ssl_version);
    local_144.data = &local_54;
    local_144.type = 4;
    if (*(int *)(in->krb5_client_princ + 0x24) == 0) {
      uVar4 = *(undefined4 *)(in->krb5_client_princ + 0x28);
    }
    else {
      uVar4 = *(undefined4 *)(*(int *)(in->krb5_client_princ + 0x24) + 8);
    }
    local_53 = (uchar)((uint)uVar4 >> 8);
    if (in->ssl_version == 2) {
      local_144.length = 3;
      local_54 = (uchar)((uint)uVar4 >> 0x10);
      local_52 = (uchar)uVar4;
    }
    else {
      local_144.length = 2;
      local_54 = local_53;
      local_53 = (uchar)uVar4;
    }
    if (*(int *)(in->krb5_client_princ + 0x20) != 0) {
      local_169 = (uchar)*(int *)(in->krb5_client_princ + 0x20);
      local_134.data = &local_169;
      local_134.length = 1;
      local_134.type = 4;
    }
    local_124.length = in->master_key_length;
    local_124.type = 4;
    local_114.type = 4;
    local_104.type = 4;
    local_f4.type = 4;
    local_124.data = in->master_key;
    local_114.length = in->session_id_length;
    local_114.data = in->session_id;
    local_104.length = in->sid_ctx_length;
    local_104.data = in->sid_ctx;
    local_f4.length = in->key_arg_length;
    local_f4.data = in->key_arg;
    if (*(int *)(in->krb5_client_princ + 0x1c) != 0) {
      local_e4.data = local_40;
      local_e4.length = 8;
      local_e4.type = 2;
      ASN1_INTEGER_set(&local_e4,*(int *)(in->krb5_client_princ + 0x1c));
    }
    if (*(int *)(in->krb5_client_princ + 0x18) != 0) {
      local_d4.data = local_38;
      local_d4.length = 8;
      local_d4.type = 2;
      ASN1_INTEGER_set(&local_d4,*(int *)(in->krb5_client_princ + 0x18));
    }
    if (*(int *)(in->krb5_client_princ + 0x10) != 0) {
      local_c4.data = local_30;
      local_c4.length = 8;
      local_c4.type = 2;
      ASN1_INTEGER_set(&local_c4,*(int *)(in->krb5_client_princ + 0x10));
    }
    puVar1 = *(uchar **)(in->krb5_client_princ + 0x40);
    if (puVar1 != (uchar *)0x0) {
      local_b4.length = strlen((char *)puVar1);
      local_b4.type = 4;
      local_b4.data = puVar1;
    }
    if (*(uchar **)(in->krb5_client_princ + 0x54) != (uchar *)0x0) {
      local_94.length = *(int *)(in->krb5_client_princ + 0x58);
      local_94.type = 4;
      local_94.data = *(uchar **)(in->krb5_client_princ + 0x54);
    }
    if (0 < *(int *)(in->krb5_client_princ + 0x5c)) {
      local_a4.data = local_28;
      local_a4.length = 8;
      local_a4.type = 2;
      ASN1_INTEGER_set(&local_a4,*(int *)(in->krb5_client_princ + 0x5c));
    }
    puVar1 = (uchar *)in->krb5_client_princ_len;
    if (puVar1 != (uchar *)0x0) {
      local_84.length = strlen((char *)puVar1);
      local_84.type = 4;
      local_84.data = puVar1;
    }
    puVar1 = *(uchar **)in->krb5_client_princ;
    if (puVar1 != (uchar *)0x0) {
      local_74.length = strlen((char *)puVar1);
      local_74.type = 4;
      local_74.data = puVar1;
    }
    puVar1 = *(uchar **)(in->krb5_client_princ + 0x60);
    if (puVar1 != (uchar *)0x0) {
      local_64.length = strlen((char *)puVar1);
      local_64.type = 4;
      local_64.data = puVar1;
    }
    iVar3 = i2d_ASN1_INTEGER(&local_164,(uchar **)0x0);
    iVar5 = i2d_ASN1_INTEGER(&local_154,(uchar **)0x0);
    iVar6 = i2d_ASN1_OCTET_STRING(&local_144,(uchar **)0x0);
    iVar7 = i2d_ASN1_OCTET_STRING(&local_114,(uchar **)0x0);
    iVar8 = i2d_ASN1_OCTET_STRING(&local_124,(uchar **)0x0);
    iVar8 = iVar3 + iVar5 + iVar6 + iVar7 + iVar8;
    if (in->key_arg_length != 0) {
      iVar3 = i2d_ASN1_OCTET_STRING(&local_f4,(uchar **)0x0);
      iVar8 = iVar8 + iVar3;
    }
    local_180 = 0;
    if (*(int *)(in->krb5_client_princ + 0x1c) != 0) {
      local_180 = i2d_ASN1_INTEGER(&local_e4,(uchar **)0x0);
      iVar3 = ASN1_object_size(1,local_180,1);
      iVar8 = iVar8 + iVar3;
    }
    local_174 = 0;
    if (*(int *)(in->krb5_client_princ + 0x18) != 0) {
      local_174 = i2d_ASN1_INTEGER(&local_d4,(uchar **)0x0);
      iVar3 = ASN1_object_size(1,local_174,2);
      iVar8 = iVar8 + iVar3;
    }
    if (*(X509 **)(in->krb5_client_princ + 0xc) == (X509 *)0x0) {
      local_170 = 0;
    }
    else {
      local_170 = i2d_X509(*(X509 **)(in->krb5_client_princ + 0xc),(uchar **)0x0);
      iVar3 = ASN1_object_size(1,local_170,3);
      iVar8 = iVar8 + iVar3;
    }
    iVar5 = i2d_ASN1_OCTET_STRING(&local_104,(uchar **)0x0);
    iVar3 = ASN1_object_size(1,iVar5,4);
    iVar8 = iVar8 + iVar3;
    local_17c = 0;
    if (*(int *)(in->krb5_client_princ + 0x10) != 0) {
      local_17c = i2d_ASN1_INTEGER(&local_c4,(uchar **)0x0);
      iVar3 = ASN1_object_size(1,local_17c,5);
      iVar8 = iVar8 + iVar3;
    }
    local_18c = 0;
    if (0 < *(int *)(in->krb5_client_princ + 0x5c)) {
      local_18c = i2d_ASN1_INTEGER(&local_a4,(uchar **)0x0);
      iVar3 = ASN1_object_size(1,local_18c,9);
      iVar8 = iVar8 + iVar3;
    }
    local_19c = 0;
    if (*(int *)(in->krb5_client_princ + 0x54) != 0) {
      local_19c = i2d_ASN1_OCTET_STRING(&local_94,(uchar **)0x0);
      iVar3 = ASN1_object_size(1,local_19c,10);
      iVar8 = iVar8 + iVar3;
    }
    local_1a0 = 0;
    if (*(int *)(in->krb5_client_princ + 0x40) != 0) {
      local_1a0 = i2d_ASN1_OCTET_STRING(&local_b4,(uchar **)0x0);
      iVar3 = ASN1_object_size(1,local_1a0,6);
      iVar8 = iVar8 + iVar3;
    }
    local_178 = 0;
    if (*(int *)(in->krb5_client_princ + 0x20) != 0) {
      local_178 = i2d_ASN1_OCTET_STRING(&local_134,(uchar **)0x0);
      iVar3 = ASN1_object_size(1,local_178,0xb);
      iVar8 = iVar8 + iVar3;
    }
    local_198 = 0;
    if (in->krb5_client_princ_len != 0) {
      local_198 = i2d_ASN1_OCTET_STRING(&local_84,(uchar **)0x0);
      iVar3 = ASN1_object_size(1,local_198,7);
      iVar8 = iVar8 + iVar3;
    }
    local_194 = 0;
    if (*(int *)in->krb5_client_princ != 0) {
      local_194 = i2d_ASN1_OCTET_STRING(&local_74,(uchar **)0x0);
      iVar3 = ASN1_object_size(1,local_194,8);
      iVar8 = iVar8 + iVar3;
    }
    local_190 = 0;
    if (*(int *)(in->krb5_client_princ + 0x60) != 0) {
      local_190 = i2d_ASN1_OCTET_STRING(&local_64,(uchar **)0x0);
      iVar3 = ASN1_object_size(1,local_190,0xc);
      iVar8 = iVar8 + iVar3;
    }
    iVar3 = ASN1_object_size(1,iVar8,0x10);
    if (pp != (uchar **)0x0) {
      local_168 = *pp;
      ASN1_put_object(&local_168,1,iVar8,0x10,0);
      i2d_ASN1_INTEGER(&local_164,&local_168);
      i2d_ASN1_INTEGER(&local_154,&local_168);
      i2d_ASN1_OCTET_STRING(&local_144,&local_168);
      i2d_ASN1_OCTET_STRING(&local_114,&local_168);
      i2d_ASN1_OCTET_STRING(&local_124,&local_168);
      pbVar2 = local_168;
      if (in->key_arg_length != 0) {
        i2d_ASN1_OCTET_STRING(&local_f4,&local_168);
        *pbVar2 = *pbVar2 & 0x20 | 0x80;
      }
      if (*(int *)(in->krb5_client_princ + 0x1c) != 0) {
        ASN1_put_object(&local_168,1,local_180,1,0x80);
        i2d_ASN1_INTEGER(&local_e4,&local_168);
      }
      if (*(int *)(in->krb5_client_princ + 0x18) != 0) {
        ASN1_put_object(&local_168,1,local_174,2,0x80);
        i2d_ASN1_INTEGER(&local_d4,&local_168);
      }
      if (*(int *)(in->krb5_client_princ + 0xc) != 0) {
        ASN1_put_object(&local_168,1,local_170,3,0x80);
        i2d_X509(*(X509 **)(in->krb5_client_princ + 0xc),&local_168);
      }
      ASN1_put_object(&local_168,1,iVar5,4,0x80);
      i2d_ASN1_OCTET_STRING(&local_104,&local_168);
      if (*(int *)(in->krb5_client_princ + 0x10) != 0) {
        ASN1_put_object(&local_168,1,local_17c,5,0x80);
        i2d_ASN1_INTEGER(&local_c4,&local_168);
      }
      if (*(int *)(in->krb5_client_princ + 0x40) != 0) {
        ASN1_put_object(&local_168,1,local_1a0,6,0x80);
        i2d_ASN1_OCTET_STRING(&local_b4,&local_168);
      }
      if (in->krb5_client_princ_len != 0) {
        ASN1_put_object(&local_168,1,local_198,7,0x80);
        i2d_ASN1_OCTET_STRING(&local_84,&local_168);
      }
      if (*(int *)in->krb5_client_princ != 0) {
        ASN1_put_object(&local_168,1,local_194,8,0x80);
        i2d_ASN1_OCTET_STRING(&local_74,&local_168);
      }
      if (0 < *(int *)(in->krb5_client_princ + 0x5c)) {
        ASN1_put_object(&local_168,1,local_18c,9,0x80);
        i2d_ASN1_INTEGER(&local_a4,&local_168);
      }
      if (*(int *)(in->krb5_client_princ + 0x54) != 0) {
        ASN1_put_object(&local_168,1,local_19c,10,0x80);
        i2d_ASN1_OCTET_STRING(&local_94,&local_168);
      }
      if (*(int *)(in->krb5_client_princ + 0x20) != 0) {
        ASN1_put_object(&local_168,1,local_178,0xb,0x80);
        i2d_ASN1_OCTET_STRING(&local_134,&local_168);
      }
      if (*(int *)(in->krb5_client_princ + 0x60) != 0) {
        ASN1_put_object(&local_168,1,local_190,0xc,0x80);
        i2d_ASN1_OCTET_STRING(&local_64,&local_168);
      }
      *pp = local_168;
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}

