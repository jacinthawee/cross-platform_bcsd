
int X509_NAME_print_ex(BIO *out,X509_NAME *nm,int indent,ulong flags)

{
  byte bVar1;
  undefined *puVar2;
  _union_257 _Var3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  _union_257 _Var9;
  _union_257 _Var10;
  uint uVar11;
  _union_257 _Var12;
  uint uVar13;
  uint uVar14;
  ASN1_TYPE *a;
  _union_257 unaff_s0;
  uint uVar15;
  stack_st_X509_NAME_ENTRY *psVar16;
  BIO *unaff_s1;
  _union_257 unaff_s2;
  _union_257 _Var17;
  BUF_MEM *pBVar18;
  BUF_MEM *pBVar19;
  X509_NAME *pXVar20;
  _union_257 unaff_s3;
  byte *pbVar21;
  _union_257 unaff_s4;
  BUF_MEM *pBVar22;
  _union_257 unaff_s5;
  X509_NAME *unaff_s6;
  uint uVar23;
  BUF_MEM *unaff_s7;
  code *pcVar24;
  byte *pbVar25;
  X509_NAME *unaff_s8;
  int iStack_248;
  uint uStack_244;
  char cStack_21d;
  _union_257 _Stack_21c;
  ASN1_TYPE AStack_218;
  byte abStack_210 [4];
  byte bStack_20c;
  byte bStack_20b;
  char cStack_208;
  char cStack_207;
  int iStack_1fc;
  _union_257 _Stack_1f8;
  BIO *pBStack_1f4;
  _union_257 _Stack_1f0;
  _union_257 _Stack_1ec;
  _union_257 _Stack_1e8;
  _union_257 _Stack_1e4;
  X509_NAME *pXStack_1e0;
  BUF_MEM *pBStack_1dc;
  X509_NAME *pXStack_1d8;
  code *pcStack_1d4;
  undefined *puStack_1c0;
  int iStack_1b4;
  _union_257 _Stack_1b0;
  uint uStack_1ac;
  _union_257 _Stack_1a8;
  _union_257 _Stack_1a4;
  uint uStack_1a0;
  uint uStack_19c;
  _union_257 _Stack_198;
  int iStack_194;
  _union_257 _Stack_190;
  undefined *puStack_18c;
  char *pcStack_188;
  _union_257 _Stack_184;
  ASN1_TYPE **ppAStack_180;
  X509_NAME *pXStack_17c;
  int iStack_178;
  int iStack_174;
  _union_257 _Stack_170;
  undefined *puStack_16c;
  uint uStack_168;
  char *pcStack_164;
  X509_NAME aXStack_15c [4];
  ASN1_TYPE *pAStack_10c;
  _union_257 _Stack_108;
  BIO *pBStack_104;
  _union_257 _Stack_100;
  _union_257 _Stack_fc;
  _union_257 _Stack_f8;
  _union_257 _Stack_f4;
  X509_NAME *pXStack_f0;
  BUF_MEM *pBStack_ec;
  X509_NAME *pXStack_e8;
  code *pcStack_e4;
  ulong uStack_d4;
  undefined *local_d0;
  int local_c8;
  int local_c4;
  _union_257 local_c0;
  uint local_bc;
  X509_NAME *local_b8;
  _union_257 local_b4;
  uint local_b0;
  uint local_ac;
  _union_257 local_a8;
  _union_257 local_a4;
  _union_257 local_a0;
  _union_257 local_9c;
  _union_257 local_98;
  BIO **local_94;
  _union_257 local_90;
  uint local_8c;
  _union_257 local_88;
  _union_257 local_84;
  undefined auStack_7c [80];
  BIO *local_2c;
  
  local_94 = (BIO **)PTR___stack_chk_guard_006aabf0;
  local_d0 = &_gp;
  local_2c = *(BIO **)PTR___stack_chk_guard_006aabf0;
  pXStack_1d8 = unaff_s8;
  local_b8 = nm;
  if (flags == 0) {
    _Var9.boolean = X509_NAME_print(out,nm,indent);
    _Stack_1f8 = (_union_257)indent;
    uStack_d4 = flags;
    _Stack_108 = unaff_s0;
    out = unaff_s1;
  }
  else {
    _Stack_1f8 = (_union_257)indent;
    uStack_d4 = flags;
    if (indent < 0) {
      _Stack_108.ptr = (char *)0x0;
      if ((flags & 0xf0000) == 0x20000) goto LAB_00552f70;
LAB_00552db4:
      uVar11 = flags & 0xf0000;
      if (uVar11 < 0x20001) {
        if (uVar11 != 0x10000) {
LAB_00552d4c:
          _Var9.boolean = -1;
          pXStack_1d8 = unaff_s8;
          goto LAB_00552d50;
        }
        unaff_s3.ptr = (char *)0x0;
        local_9c.boolean = 1;
        local_a8.boolean = 1;
        local_90.ptr = "+";
        local_a0.ptr = ",";
      }
      else if (uVar11 == 0x30000) {
        unaff_s3.ptr = (char *)0x0;
        local_9c.boolean = 3;
        local_a8.boolean = (ASN1_BOOLEAN)&SUB_00000002;
        local_90.ptr = " + ";
        local_a0.ptr = "; ";
      }
      else {
        if (uVar11 != 0x40000) goto LAB_00552d4c;
        local_9c.boolean = 3;
        local_a8.boolean = 1;
        local_90.ptr = " + ";
        local_a0.ptr = "\n";
        unaff_s3 = _Stack_108;
      }
      if ((int)(flags << 8) < 0) goto LAB_00552e10;
LAB_00552fac:
      local_b4.boolean = 1;
      local_a4.ptr = "=";
      _Var9 = _Stack_108;
    }
    else {
      _Stack_108 = (_union_257)indent;
      if ((indent != 0) && (out != (BIO *)0x0)) {
        unaff_s2.ptr = (char *)0x0;
        unaff_s3.ptr = " ";
        pcVar24 = (code *)PTR_BIO_write_006a7f14;
        do {
          _Stack_1f8.boolean = 1;
          nm = (X509_NAME *)unaff_s3.ptr;
          iVar8 = (*pcVar24)(out);
          if (iVar8 != 1) goto LAB_00552d4c;
          unaff_s2.ptr = (char *)((int)&(unaff_s2.asn1_string)->length + 1);
          pcVar24 = *(code **)(local_d0 + -0x7fcc);
        } while ((char *)indent != unaff_s2.ptr);
      }
      if ((flags & 0xf0000) != 0x20000) goto LAB_00552db4;
LAB_00552f70:
      local_9c.boolean = 3;
      local_a8.boolean = (ASN1_BOOLEAN)&SUB_00000002;
      local_90.ptr = " + ";
      local_a0.ptr = ", ";
      unaff_s3.ptr = (char *)0x0;
      if (-1 < (int)(flags << 8)) goto LAB_00552fac;
LAB_00552e10:
      local_b4.boolean = 3;
      local_a4.ptr = " = ";
      _Var9 = _Stack_108;
    }
    local_bc = flags & 0x600000;
    iVar8 = (**(code **)(local_d0 + -0x7e6c))(local_b8);
    _Stack_108 = _Var9;
    if (0 < iVar8) {
      local_ac = 0x80;
      unaff_s7 = (BUF_MEM *)(iVar8 + -1);
      local_c8 = 0;
      local_98.ptr = auStack_7c;
      if (-1 < (int)(flags << 7)) {
        local_ac = 0;
      }
      unaff_s2.ptr = " ";
      local_88.ptr = "";
      local_b0 = flags & 0x100000;
      local_8c = flags & 0x2000000;
      unaff_s8 = (X509_NAME *)0xffffffff;
      do {
        if (local_b0 == 0) {
          unaff_s4.ptr = (char *)(**(code **)(local_d0 + -0x7cc0))(local_b8,local_c8);
          if (unaff_s8 == (X509_NAME *)0xffffffff) goto LAB_0055300c;
LAB_00552ed0:
          unaff_s5 = local_9c;
          _Var12 = local_a8;
          pXStack_1d8 = (X509_NAME *)(unaff_s4.asn1_string)->data;
          _Stack_108 = _Var9;
          if (pXStack_1d8 == unaff_s8) {
            if (out != (BIO *)0x0) {
              nm = (X509_NAME *)local_90;
              _Stack_1f8 = local_9c;
              pXVar20 = (X509_NAME *)(**(code **)(local_d0 + -0x7fcc))(out);
              if ((X509_NAME *)unaff_s5.ptr != pXVar20) goto LAB_00552d4c;
              pXStack_1d8 = (X509_NAME *)(unaff_s4.asn1_string)->data;
            }
            _Var9.ptr = _Var9.ptr + local_9c.ptr;
          }
          else if (out == (BIO *)0x0) {
            _Var9.ptr = unaff_s3.ptr + local_a8.ptr + _Var9.ptr;
          }
          else {
            nm = (X509_NAME *)local_a0;
            _Stack_1f8 = local_a8;
            pXVar20 = (X509_NAME *)(**(code **)(local_d0 + -0x7fcc))(out);
            unaff_s5 = _Var12;
            if ((X509_NAME *)_Var12.ptr != pXVar20) goto LAB_00552d4c;
            unaff_s5.ptr = (char *)0x0;
            _Stack_108.ptr = local_a8.ptr + _Var9.ptr;
            if ((X509_NAME *)unaff_s3.ptr == (X509_NAME *)0x0) {
              pXStack_1d8 = (X509_NAME *)(unaff_s4.asn1_string)->data;
            }
            else {
              do {
                _Stack_1f8.boolean = 1;
                nm = (X509_NAME *)unaff_s2.ptr;
                iVar8 = (**(code **)(local_d0 + -0x7fcc))(out);
                if (iVar8 != 1) goto LAB_00552d4c;
                unaff_s5.ptr = (char *)((int)&(unaff_s5.asn1_string)->length + 1);
              } while (unaff_s3.ptr != unaff_s5.ptr);
              pXStack_1d8 = (X509_NAME *)(unaff_s4.asn1_string)->data;
            }
            _Var9.ptr = unaff_s3.ptr + _Stack_108.ptr;
          }
        }
        else {
          unaff_s4.ptr = (char *)(**(code **)(local_d0 + -0x7cc0))(local_b8,unaff_s7);
          if (unaff_s8 != (X509_NAME *)0xffffffff) goto LAB_00552ed0;
LAB_0055300c:
          pXStack_1d8 = (X509_NAME *)(unaff_s4.asn1_string)->data;
        }
        unaff_s5.ptr = (char *)(**(code **)(local_d0 + -0x7cb8))(unaff_s4.ptr);
        local_c0.ptr = (char *)(**(code **)(local_d0 + -0x7cbc))(unaff_s4.ptr);
        local_c4 = (**(code **)(local_d0 + -0x7cb4))(unaff_s5.ptr);
        nm = (X509_NAME *)local_98;
        unaff_s8 = pXStack_1d8;
        if (local_bc != 0x600000) {
          _Stack_108 = _Var9;
          if ((local_bc == 0x400000) || (local_c4 == 0)) {
            uStack_d4 = 1;
            (**(code **)(local_d0 + -0x6124))(local_98.ptr,0x50,unaff_s5.ptr);
            unaff_s6 = (X509_NAME *)0x0;
            unaff_s5.ptr = (char *)(**(code **)(local_d0 + -0x53b0))(nm);
            unaff_s4 = (_union_257)nm;
LAB_00553194:
            if (out == (BIO *)0x0) {
              if (unaff_s5.boolean < (int)unaff_s6) {
                unaff_s6 = (X509_NAME *)((int)unaff_s6 - (int)unaff_s5);
                if (local_8c != 0) goto LAB_005531c8;
                unaff_s6 = (X509_NAME *)((int)&unaff_s6->entries + (int)unaff_s5.ptr);
              }
            }
            else {
              _Stack_1f8 = unaff_s5;
              pXVar20 = (X509_NAME *)(**(code **)(local_d0 + -0x7fcc))(out);
              if ((X509_NAME *)unaff_s5.ptr != pXVar20) goto LAB_00552d4c;
              if ((unaff_s5.boolean < (int)unaff_s6) && (local_8c != 0)) {
                unaff_s6 = (X509_NAME *)((int)unaff_s6 - (int)unaff_s5);
                unaff_s4 = local_b4;
LAB_005531c8:
                if ((0 < (int)unaff_s6) && (unaff_s4.ptr = (char *)0x0, out != (BIO *)0x0)) {
                  pcVar24 = *(code **)(local_d0 + -0x7fcc);
                  do {
                    _Stack_1f8.boolean = 1;
                    nm = (X509_NAME *)unaff_s2.ptr;
                    iVar8 = (*pcVar24)(out);
                    if (iVar8 != 1) goto LAB_00552d4c;
                    unaff_s4.ptr = (char *)((int)&(unaff_s4.asn1_string)->length + 1);
                    pcVar24 = *(code **)(local_d0 + -0x7fcc);
                  } while (unaff_s6 != (X509_NAME *)unaff_s4.ptr);
                }
                _Var9.ptr = _Var9.ptr + (int)unaff_s6;
                if (out == (BIO *)0x0) goto LAB_00553100;
              }
LAB_005530e0:
              unaff_s4 = local_b4;
              nm = (X509_NAME *)local_a4;
              _Stack_1f8 = local_b4;
              pXVar20 = (X509_NAME *)(**(code **)(local_d0 + -0x7fcc))(out);
              _Stack_108 = _Var9;
              if ((X509_NAME *)unaff_s4.ptr != pXVar20) goto LAB_00552d4c;
            }
          }
          else {
            if (local_bc == 0) {
              unaff_s6 = (X509_NAME *)&DAT_0000000a;
              local_84.ptr = (char *)(**(code **)(local_d0 + -0x7d44))(local_c4);
              unaff_s5.ptr = (char *)(**(code **)(local_d0 + -0x53b0))(local_84.ptr);
              nm = (X509_NAME *)local_84;
              goto LAB_00553194;
            }
            if (local_bc == 0x200000) {
              unaff_s6 = (X509_NAME *)&DAT_00000019;
              local_84.ptr = (char *)(**(code **)(local_d0 + -0x7cc4))(local_c4);
              unaff_s5.ptr = (char *)(**(code **)(local_d0 + -0x53b0))(local_84.ptr);
              nm = (X509_NAME *)local_84;
              goto LAB_00553194;
            }
            if (out != (BIO *)0x0) {
              _Stack_1f8.ptr = (char *)0x0;
              nm = (X509_NAME *)local_88;
              unaff_s5.ptr = (char *)(**(code **)(local_d0 + -0x7fcc))(out);
              if ((X509_NAME *)unaff_s5.ptr == (X509_NAME *)0x0) goto LAB_005530e0;
              goto LAB_00552d4c;
            }
            unaff_s5.ptr = (char *)0x0;
          }
LAB_00553100:
          unaff_s5.ptr = local_b4.ptr + unaff_s5.ptr;
          _Var9.ptr = _Var9.ptr + unaff_s5.ptr;
        }
        uVar11 = local_ac;
        if (local_c4 != 0) {
          uVar11 = 0;
        }
        nm = (X509_NAME *)(flags | uVar11);
        _Stack_1f8 = local_c0;
        iVar8 = do_print_ex_constprop_2(out);
        _Stack_108 = _Var9;
        if (iVar8 < 0) goto LAB_00552d4c;
        _Var9.ptr = _Var9.ptr + iVar8;
        unaff_s7 = (BUF_MEM *)((int)&unaff_s7[-1].max + 3);
        local_c8 = local_c8 + 1;
        _Stack_108.ptr = _Var9.ptr;
      } while (unaff_s7 != (BUF_MEM *)0xffffffff);
    }
  }
LAB_00552d50:
  if (local_2c == *local_94) {
    return (int)_Var9.ptr;
  }
  pcStack_e4 = X509_NAME_print_ex_fp;
  pBStack_1f4 = local_2c;
  (**(code **)(local_d0 + -0x5328))();
  ppAStack_180 = (ASN1_TYPE **)PTR___stack_chk_guard_006aabf0;
  puStack_1c0 = &_gp;
  pAStack_10c = *(ASN1_TYPE **)PTR___stack_chk_guard_006aabf0;
  _Var9 = (_union_257)nm;
  _Var12 = _Stack_1f8;
  _Stack_1ec = unaff_s3;
  pBStack_1dc = unaff_s7;
  _Stack_1a8 = (_union_257)nm;
  pBStack_104 = out;
  _Stack_100 = unaff_s2;
  _Stack_fc = unaff_s3;
  _Stack_f8 = unaff_s4;
  _Stack_f4 = unaff_s5;
  pXStack_f0 = unaff_s6;
  pBStack_ec = unaff_s7;
  pXStack_e8 = pXStack_1d8;
  if (uStack_d4 == 0) {
    _Var9.ptr = (char *)0x0;
    pBStack_1f4 = (BIO *)(*(code *)PTR_BIO_new_fp_006a835c)();
    _Var17 = (_union_257)nm;
    if (pBStack_1f4 == (BIO *)0x0) goto LAB_00553580;
    _Var9 = (_union_257)nm;
    _Var10.boolean = X509_NAME_print(pBStack_1f4,nm,_Stack_1f8.boolean);
    (**(code **)(puStack_1c0 + -0x7f70))(pBStack_1f4);
    _Var12 = _Stack_1f8;
    _Stack_1f8.boolean = _Var10.boolean;
    unaff_s2 = (_union_257)nm;
  }
  else {
    if ((int)_Stack_1f8 < 0) {
      _Var10.ptr = (char *)0x0;
    }
    else {
      _Var10 = _Stack_1f8;
      if (((X509_NAME *)_Stack_1f8.ptr != (X509_NAME *)0x0) &&
         (_Stack_1ec.ptr = "s\n", pBStack_1f4 != (BIO *)0x0)) {
        _Stack_1ec.ptr = " ";
        _Var17.ptr = (char *)0x0;
        do {
          _Var12.boolean = 1;
          _Var9.boolean = 1;
          iVar8 = (**(code **)(puStack_1c0 + -0x5364))(&DAT_0063f0b8,1,1,pBStack_1f4);
          if (iVar8 != 1) goto LAB_00553580;
          unaff_s2.ptr = (char *)((int)&(_Var17.asn1_string)->length + 1);
          _Var17.ptr = unaff_s2.ptr;
        } while (_Stack_1f8.ptr != unaff_s2.ptr);
      }
    }
    uVar11 = uStack_d4 & 0xf0000;
    unaff_s4.ptr = (char *)0x0;
    _Stack_1f8 = _Var10;
    if (uVar11 == 0x20000) {
      _Stack_184.boolean = (ASN1_BOOLEAN)&SUB_00000002;
      _Stack_170.boolean = 3;
      iStack_174 = 3;
      iStack_178 = 2;
      puStack_16c = &DAT_0066a068;
      pcStack_188 = ", ";
    }
    else {
      _Var17 = unaff_s2;
      if (uVar11 < 0x20001) {
        if (uVar11 != 0x10000) {
LAB_00553580:
          _Var10.boolean = -1;
          unaff_s2 = _Var17;
          pBStack_1dc = unaff_s7;
          goto LAB_00553584;
        }
        unaff_s4.ptr = (char *)0x0;
        _Stack_184.boolean = 1;
        _Stack_170.boolean = 1;
        iStack_174 = 1;
        iStack_178 = 1;
        puStack_16c = &DAT_0066a06c;
        pcStack_188 = ",";
      }
      else if (uVar11 == 0x30000) {
        unaff_s4.ptr = (char *)0x0;
        _Stack_184.boolean = (ASN1_BOOLEAN)&SUB_00000002;
        _Stack_170.boolean = 3;
        iStack_174 = 3;
        iStack_178 = 2;
        puStack_16c = &DAT_0066a068;
        pcStack_188 = "; ";
      }
      else {
        if (uVar11 != 0x40000) goto LAB_00553580;
        _Stack_184.boolean = 1;
        _Stack_170.boolean = 3;
        iStack_174 = 3;
        iStack_178 = 1;
        puStack_16c = &DAT_0066a068;
        pcStack_188 = "\n";
        unaff_s4 = _Var10;
      }
    }
    if ((int)(uStack_d4 << 8) < 0) {
      _Stack_190.boolean = 3;
      iStack_194 = 3;
      puStack_18c = &DAT_0066a074;
    }
    else {
      _Stack_190.boolean = 1;
      iStack_194 = 1;
      puStack_18c = &DAT_00669e18;
    }
    uStack_1ac = uStack_d4 & 0x600000;
    iVar8 = (**(code **)(puStack_1c0 + -0x7e6c))(_Stack_1a8.ptr);
    if (0 < iVar8) {
      unaff_s6 = (X509_NAME *)(iVar8 + -1);
      iStack_1b4 = 0;
      uStack_19c = 0x80;
      if (-1 < (int)(uStack_d4 << 7)) {
        uStack_19c = 0;
      }
      pXStack_1d8 = aXStack_15c;
      pcStack_164 = "";
      unaff_s2.ptr = " ";
      uStack_1a0 = uStack_d4 & 0x100000;
      uStack_168 = uStack_d4 & 0x2000000;
      unaff_s7 = (BUF_MEM *)0xffffffff;
      pXStack_17c = pXStack_1d8;
      do {
        _Var17.ptr = unaff_s2.ptr;
        if (uStack_1a0 == 0) {
          _Stack_1ec.ptr = (char *)(**(code **)(puStack_1c0 + -0x7cc0))(_Stack_1a8.ptr,iStack_1b4);
          if (unaff_s7 == (BUF_MEM *)0xffffffff) goto LAB_0055366c;
LAB_00553504:
          unaff_s5 = _Stack_170;
          _Var3 = _Stack_184;
          pBStack_1dc = (BUF_MEM *)(_Stack_1ec.asn1_string)->data;
          _Stack_1f8 = _Var10;
          if (pBStack_1dc == unaff_s7) {
            _Var9.boolean = 1;
            if (pBStack_1f4 != (BIO *)0x0) {
              _Var12 = _Stack_170;
              pXVar20 = (X509_NAME *)
                        (**(code **)(puStack_1c0 + -0x5364))
                                  (puStack_16c,1,_Stack_170.ptr,pBStack_1f4);
              if ((X509_NAME *)unaff_s5.ptr != pXVar20) goto LAB_00553580;
              pBStack_1dc = (BUF_MEM *)(_Stack_1ec.asn1_string)->data;
            }
            _Var10.ptr = _Var10.ptr + iStack_174;
          }
          else {
            _Var9.boolean = 1;
            if (pBStack_1f4 == (BIO *)0x0) {
              _Var10.ptr = unaff_s4.ptr + (int)(_Var10.boolean + iStack_178);
            }
            else {
              _Var12 = _Stack_184;
              pXVar20 = (X509_NAME *)
                        (**(code **)(puStack_1c0 + -0x5364))
                                  (pcStack_188,1,_Stack_184.ptr,pBStack_1f4);
              unaff_s5 = _Var3;
              if (pXVar20 != (X509_NAME *)_Var3.ptr) goto LAB_00553580;
              unaff_s5.ptr = (char *)0x0;
              _Stack_1f8.ptr = (char *)(_Var10.boolean + iStack_178);
              if ((X509_NAME *)unaff_s4.ptr == (X509_NAME *)0x0) {
                pBStack_1dc = (BUF_MEM *)(_Stack_1ec.asn1_string)->data;
              }
              else {
                do {
                  _Var12.boolean = 1;
                  _Var9.boolean = 1;
                  iVar8 = (**(code **)(puStack_1c0 + -0x5364))(&DAT_0063f0b8,1,1,pBStack_1f4);
                  if (iVar8 != 1) goto LAB_00553580;
                  unaff_s5.ptr = (char *)((int)&(unaff_s5.asn1_string)->length + 1);
                } while (unaff_s4.ptr != unaff_s5.ptr);
                pBStack_1dc = (BUF_MEM *)(_Stack_1ec.asn1_string)->data;
              }
              _Var10.ptr = unaff_s4.ptr + (int)_Stack_1f8.ptr;
            }
          }
        }
        else {
          _Stack_1ec.ptr = (char *)(**(code **)(puStack_1c0 + -0x7cc0))(_Stack_1a8.ptr,unaff_s6);
          if (unaff_s7 != (BUF_MEM *)0xffffffff) goto LAB_00553504;
LAB_0055366c:
          pBStack_1dc = (BUF_MEM *)(_Stack_1ec.asn1_string)->data;
        }
        unaff_s5.ptr = (char *)(**(code **)(puStack_1c0 + -0x7cb8))(_Stack_1ec.ptr);
        _Stack_1b0.ptr = (char *)(**(code **)(puStack_1c0 + -0x7cbc))(_Stack_1ec.ptr);
        _Stack_1ec.ptr = (char *)(**(code **)(puStack_1c0 + -0x7cb4))(unaff_s5.ptr);
        pXVar20 = pXStack_17c;
        unaff_s7 = pBStack_1dc;
        if (uStack_1ac != 0x600000) {
          _Stack_1f8 = _Var10;
          pXStack_1d8 = pXVar20;
          if ((uStack_1ac == 0x400000) || ((X509_NAME *)_Stack_1ec.ptr == (X509_NAME *)0x0)) {
            (**(code **)(puStack_1c0 + -0x6124))(pXStack_17c,0x50,unaff_s5.ptr,1);
            unaff_s5.ptr = (char *)0x0;
            _Stack_1a4.ptr = (char *)(**(code **)(puStack_1c0 + -0x53b0))(pXVar20);
LAB_005537f8:
            if (pBStack_1f4 == (BIO *)0x0) {
              if (_Stack_1a4.boolean < unaff_s5.boolean) {
                unaff_s5.ptr = unaff_s5.ptr + -_Stack_1a4.boolean;
                if (uStack_168 != 0) goto LAB_00553838;
                unaff_s5.ptr = unaff_s5.ptr + _Stack_1a4.ptr;
              }
            }
            else {
              _Var9.boolean = 1;
              _Var12 = _Stack_1a4;
              _Stack_198 = _Stack_1a4;
              pXVar20 = (X509_NAME *)
                        (**(code **)(puStack_1c0 + -0x5364))
                                  (pXStack_1d8,1,_Stack_1a4.ptr,pBStack_1f4);
              if (pXVar20 != (X509_NAME *)_Stack_198.ptr) goto LAB_00553580;
              if ((_Stack_198.boolean < unaff_s5.boolean) &&
                 (unaff_s5.ptr = unaff_s5.ptr + -_Stack_198.boolean, uStack_168 != 0)) {
LAB_00553838:
                if ((0 < unaff_s5.boolean) &&
                   (pXStack_1d8 = (X509_NAME *)0x0, pBStack_1f4 != (BIO *)0x0)) {
                  pcVar24 = *(code **)(puStack_1c0 + -0x5364);
                  do {
                    _Var12.boolean = 1;
                    _Var9.boolean = 1;
                    iVar8 = (*pcVar24)(&DAT_0063f0b8,1,1,pBStack_1f4);
                    if (iVar8 != 1) goto LAB_00553580;
                    pXStack_1d8 = (X509_NAME *)((int)&pXStack_1d8->entries + 1);
                    pcVar24 = *(code **)(puStack_1c0 + -0x5364);
                  } while ((X509_NAME *)unaff_s5.ptr != pXStack_1d8);
                }
                _Var10.ptr = _Var10.ptr + unaff_s5.ptr;
                if (pBStack_1f4 == (BIO *)0x0) goto LAB_00553768;
              }
LAB_00553740:
              unaff_s5 = _Stack_190;
              _Var9.boolean = 1;
              _Var12 = _Stack_190;
              pXVar20 = (X509_NAME *)
                        (**(code **)(puStack_1c0 + -0x5364))
                                  (puStack_18c,1,_Stack_190.ptr,pBStack_1f4);
              _Stack_1f8 = _Var10;
              if ((X509_NAME *)unaff_s5.ptr != pXVar20) goto LAB_00553580;
            }
          }
          else {
            if (uStack_1ac == 0) {
              unaff_s5.boolean = (ASN1_BOOLEAN)&DAT_0000000a;
              pXStack_1d8 = (X509_NAME *)(**(code **)(puStack_1c0 + -0x7d44))(_Stack_1ec.ptr);
              _Stack_1a4.ptr = (char *)(**(code **)(puStack_1c0 + -0x53b0))(pXStack_1d8);
              goto LAB_005537f8;
            }
            if (uStack_1ac == 0x200000) {
              unaff_s5.boolean = (ASN1_BOOLEAN)&DAT_00000019;
              pXStack_1d8 = (X509_NAME *)(**(code **)(puStack_1c0 + -0x7cc4))(_Stack_1ec.ptr);
              _Stack_1a4.ptr = (char *)(**(code **)(puStack_1c0 + -0x53b0))(pXStack_1d8);
              goto LAB_005537f8;
            }
            if (pBStack_1f4 != (BIO *)0x0) {
              _Var12.ptr = (char *)0x0;
              _Var9.boolean = 1;
              iVar8 = (**(code **)(puStack_1c0 + -0x5364))(pcStack_164,1,0,pBStack_1f4);
              if (iVar8 == 0) {
                _Stack_1a4.ptr = (char *)0x0;
                goto LAB_00553740;
              }
              goto LAB_00553580;
            }
            _Stack_1a4.ptr = (char *)0x0;
            pXStack_1d8 = pXStack_17c;
          }
LAB_00553768:
          _Var10.ptr = _Var10.ptr + (int)(_Stack_1a4.boolean + iStack_194);
        }
        uVar11 = uStack_19c;
        if ((X509_NAME *)_Stack_1ec.ptr != (X509_NAME *)0x0) {
          uVar11 = 0;
        }
        _Var9.boolean = uStack_d4 | uVar11;
        _Var12 = _Stack_1b0;
        iVar8 = do_print_ex_constprop_3(pBStack_1f4);
        _Stack_1f8 = _Var10;
        if (iVar8 < 0) goto LAB_00553580;
        _Var10.ptr = _Var10.ptr + iVar8;
        unaff_s6 = (X509_NAME *)((int)&unaff_s6[-1].canon_enclen + 3);
        iStack_1b4 = iStack_1b4 + 1;
        _Stack_1f8.ptr = _Var10.ptr;
      } while (unaff_s6 != (X509_NAME *)0xffffffff);
    }
  }
LAB_00553584:
  if (pAStack_10c == *ppAStack_180) {
    return (int)_Var10.ptr;
  }
  pcStack_1d4 = ASN1_STRING_print_ex;
  a = pAStack_10c;
  (**(code **)(puStack_1c0 + -0x5328))();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  uVar11 = _Var12.boolean & 0xf;
  cStack_21d = '\0';
  iStack_1fc = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar8 = (_Var9.asn1_string)->type;
  _Stack_1f0 = unaff_s2;
  _Stack_1e8 = unaff_s4;
  _Stack_1e4 = unaff_s5;
  pXStack_1e0 = unaff_s6;
  if ((_Var12.boolean & 0x40U) == 0) {
    uStack_244 = 0;
  }
  else {
    pcVar4 = ASN1_tag2str(iVar8);
    iVar7 = (*(code *)PTR_strlen_006aab30)(pcVar4);
    if ((a != (ASN1_TYPE *)0x0) &&
       ((iVar5 = (*(code *)PTR_BIO_write_006a7f14)(a,pcVar4,iVar7), iVar7 != iVar5 ||
        (iVar5 = (*(code *)PTR_BIO_write_006a7f14)(a,":",1), iVar5 != 1)))) goto LAB_00550980;
    uStack_244 = iVar7 + 1;
  }
  if ((_Var12.boolean & 0x80U) != 0) {
LAB_00550958:
    if (a == (ASN1_TYPE *)0x0) {
      a = &AStack_218;
      if ((_Var12.boolean & 0x200U) != 0) {
        AStack_218.type = (_Var9.asn1_string)->type;
        AStack_218.value = _Var9;
        iVar8 = i2d_ASN1_TYPE(a,(uchar **)0x0);
        _Var9.ptr = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar8,"a_strex.c",0x119);
        if ((X509_NAME *)_Var9.ptr != (X509_NAME *)0x0) {
          _Stack_21c.ptr = _Var9.ptr;
          i2d_ASN1_TYPE(a,(uchar **)&_Stack_21c.ptr);
          goto LAB_00551724;
        }
        goto LAB_00550980;
      }
      psVar16 = (stack_st_X509_NAME_ENTRY *)(_Var9.asn1_string)->length;
    }
    else {
      iVar8 = (*(code *)PTR_BIO_write_006a7f14)(a,&DAT_0066a058,1);
      if (iVar8 != 1) goto LAB_00550980;
      if ((_Var12.boolean & 0x200U) != 0) goto LAB_00551874;
      pXVar20 = (X509_NAME *)(_Var9.asn1_string)->data;
      psVar16 = (stack_st_X509_NAME_ENTRY *)(_Var9.asn1_string)->length;
      _Var9.ptr = (char *)((int)&pXVar20->entries + (int)psVar16);
      if ((X509_NAME *)_Var9.ptr != pXVar20) {
        do {
          cStack_208 = "0123456789ABCDEF"[*(byte *)&pXVar20->entries >> 4];
          cStack_207 = "0123456789ABCDEF"[*(byte *)&pXVar20->entries & 0xf];
          iVar8 = (*(code *)PTR_BIO_write_006a7f14)(a,&cStack_208,2);
          if (iVar8 != 2) goto LAB_00550980;
          pXVar20 = (X509_NAME *)((int)&pXVar20->entries + 1);
        } while ((X509_NAME *)_Var9.ptr != pXVar20);
      }
    }
    if (-1 < (int)psVar16 * 2) {
      iVar8 = uStack_244 + (int)psVar16 * 2 + 1;
      goto LAB_00550988;
    }
    goto LAB_00550980;
  }
  if ((_Var12.boolean & 0x20U) == 0) {
    if ((0x1d < iVar8 - 1U) || (uVar15 = (uint)(char)tag2nbyte[iVar8], uVar15 == 0xffffffff)) {
      if ((_Var12.boolean & 0x100U) != 0) goto LAB_00550958;
      goto LAB_00550a94;
    }
    if ((_Var12.boolean & 0x10U) != 0) {
      if (uVar15 == 0) {
        uVar15 = 1;
      }
      else {
        uVar15 = uVar15 | 8;
      }
    }
  }
  else {
LAB_00550a94:
    uVar15 = 1;
    if ((_Var12.boolean & 0x10U) != 0) {
      uVar15 = 9;
    }
  }
  psVar16 = (stack_st_X509_NAME_ENTRY *)(_Var9.object)->sn;
  pBVar18 = (BUF_MEM *)(_Var9.asn1_string)->data;
  pBVar22 = (BUF_MEM *)((int)&pBVar18->length + (int)psVar16);
  if (pBVar18 == pBVar22) {
    iStack_248 = 0;
  }
  else {
    uVar23 = uVar15 & 7;
    iStack_248 = 0;
    pBVar19 = pBVar18;
    do {
      if (pBVar18 == pBVar19) {
        uVar13 = 0x20;
        if ((_Var12.boolean & 1U) == 0) {
          uVar13 = 0;
        }
      }
      else {
        uVar13 = 0;
      }
      if (uVar23 == 1) {
        AStack_218.type = (int)*(byte *)&pBVar19->length;
        pBVar19 = (BUF_MEM *)((int)&pBVar19->length + 1);
      }
      else if (uVar23 < 2) {
        if ((uVar23 != 0) ||
           (iVar8 = (*(code *)PTR_UTF8_getc_006a9df0)(pBVar19,psVar16,&AStack_218), iVar8 < 0))
        goto LAB_00550980;
        pBVar19 = (BUF_MEM *)((int)&pBVar19->length + iVar8);
      }
      else if (uVar23 == 2) {
        AStack_218.type = (int)*(ushort *)&pBVar19->length;
        pBVar19 = (BUF_MEM *)((int)&pBVar19->length + 2);
      }
      else {
        iVar8 = -1;
        if (uVar23 != 4) goto LAB_00550988;
        AStack_218.type =
             (uint)*(byte *)((int)&pBVar19->length + 3) |
             (uint)*(byte *)((int)&pBVar19->length + 2) << 8 |
             (uint)*(byte *)((int)&pBVar19->length + 1) << 0x10 |
             (uint)*(byte *)&pBVar19->length << 0x18;
        pBVar19 = (BUF_MEM *)&pBVar19->data;
      }
      if ((pBVar22 == pBVar19) && ((_Var12.boolean & 1U) != 0)) {
        uVar13 = 0x40;
      }
      if ((uVar15 & 8) == 0) {
        iVar8 = do_esc_char_constprop_6(AStack_218.type,uVar11 | uVar13,&cStack_21d,0);
        if (iVar8 < 0) goto LAB_00550980;
        iStack_248 = iStack_248 + iVar8;
      }
      else {
        iVar8 = (*(code *)PTR_UTF8_putc_006a9dec)(abStack_210,6,AStack_218.type);
        if (0 < iVar8) {
          uVar13 = uVar11 | uVar13;
          uVar14 = (uint)abStack_210[0];
          if (uVar11 == 0) {
            uVar6 = _Var12.boolean & 4;
            if (((char)abStack_210[0] < '\0') ||
               (uVar6 = uVar13 & (byte)char_type[uVar14], (uVar6 & 0x61) == 0)) {
              if ((uVar6 & 6) == 0) {
                iVar7 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_208,0xb,"\\%02X");
                iVar7 = 3;
              }
            }
            else if ((uVar6 & 8) == 0) {
              iVar7 = 2;
            }
            else {
              iVar7 = 1;
              cStack_21d = '\x01';
            }
            iStack_248 = iStack_248 + iVar7;
            if (iVar8 == 1) goto LAB_00550d58;
            if ((char)abStack_210[1] < '\0') {
              uVar14 = _Var12.boolean & 4;
LAB_00551408:
              if ((uVar14 & 6) == 0) {
                iVar7 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_208,0xb,"\\%02X");
                iVar7 = 3;
              }
            }
            else {
              uVar14 = uVar13 & (byte)char_type[abStack_210[1]];
              if ((uVar14 & 0x61) == 0) goto LAB_00551408;
              if ((uVar14 & 8) == 0) {
                iVar7 = 2;
              }
              else {
                cStack_21d = '\x01';
                iVar7 = 1;
              }
            }
            iStack_248 = iStack_248 + iVar7;
            if (iVar8 == 2) goto LAB_00550d58;
            if ((char)abStack_210[2] < '\0') {
              uVar14 = _Var12.boolean & 4;
LAB_005513ec:
              if ((uVar14 & 6) == 0) {
                iVar7 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_208,0xb,"\\%02X");
                iVar7 = 3;
              }
            }
            else {
              uVar14 = uVar13 & (byte)char_type[abStack_210[2]];
              if ((uVar14 & 0x61) == 0) goto LAB_005513ec;
              if ((uVar14 & 8) == 0) {
                iVar7 = 2;
              }
              else {
                iVar7 = 1;
                cStack_21d = '\x01';
              }
            }
            iStack_248 = iStack_248 + iVar7;
            if (iVar8 == 3) goto LAB_00550d58;
            if ((char)abStack_210[3] < '\0') {
              uVar14 = _Var12.boolean & 4;
LAB_00551424:
              if ((uVar14 & 6) == 0) {
                iVar7 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_208,0xb,"\\%02X");
                iVar7 = 3;
              }
            }
            else {
              uVar14 = uVar13 & (byte)char_type[abStack_210[3]];
              if ((uVar14 & 0x61) == 0) goto LAB_00551424;
              if ((uVar14 & 8) == 0) {
                iVar7 = 2;
              }
              else {
                iVar7 = 1;
                cStack_21d = '\x01';
              }
            }
            iStack_248 = iStack_248 + iVar7;
            if (iVar8 == 4) goto LAB_00550d58;
            if ((char)bStack_20c < '\0') {
              uVar14 = _Var12.boolean & 4;
LAB_005513d0:
              if ((uVar14 & 6) == 0) {
                iVar7 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_208,0xb,"\\%02X");
                iVar7 = 3;
              }
            }
            else {
              uVar14 = uVar13 & (byte)char_type[bStack_20c];
              if ((uVar14 & 0x61) == 0) goto LAB_005513d0;
              if ((uVar14 & 8) == 0) {
                iVar7 = 2;
              }
              else {
                iVar7 = 1;
                cStack_21d = '\x01';
              }
            }
            iStack_248 = iStack_248 + iVar7;
            if (iVar8 == 5) goto LAB_00550d58;
            if ((char)bStack_20b < '\0') {
              uVar13 = _Var12.boolean & 4;
LAB_005513b4:
              if ((uVar13 & 6) == 0) {
                iStack_248 = iStack_248 + 1;
                goto LAB_00550d58;
              }
LAB_00551448:
              (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_208,0xb,"\\%02X");
              iStack_248 = iStack_248 + 3;
            }
            else {
              uVar13 = uVar13 & (byte)char_type[bStack_20b];
              if ((uVar13 & 0x61) == 0) goto LAB_005513b4;
LAB_00550d40:
              if ((uVar13 & 8) == 0) {
                iStack_248 = iStack_248 + 2;
              }
              else {
                iStack_248 = iStack_248 + 1;
                cStack_21d = '\x01';
              }
            }
          }
          else {
            if ((char)abStack_210[0] < '\0') {
              uVar6 = _Var12.boolean & 4;
LAB_00551390:
              if ((uVar6 & 6) == 0) {
                iVar7 = 1;
                if (uVar14 == 0x5c) {
                  iVar7 = 2;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_208,0xb,"\\%02X");
                iVar7 = 3;
              }
            }
            else {
              uVar6 = uVar13 & (byte)char_type[uVar14];
              if ((uVar6 & 0x61) == 0) goto LAB_00551390;
              if ((uVar6 & 8) == 0) {
                iVar7 = 2;
              }
              else {
                iVar7 = 1;
                cStack_21d = '\x01';
              }
            }
            iStack_248 = iStack_248 + iVar7;
            if (iVar8 == 1) goto LAB_00550d58;
            if ((char)abStack_210[1] < '\0') {
              uVar14 = _Var12.boolean & 4;
LAB_00551590:
              if ((uVar14 & 6) == 0) {
                iVar7 = 2;
                if (abStack_210[1] != 0x5c) {
                  iVar7 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_208,0xb,"\\%02X");
                iVar7 = 3;
              }
            }
            else {
              uVar14 = uVar13 & (byte)char_type[abStack_210[1]];
              if ((uVar14 & 0x61) == 0) goto LAB_00551590;
              if ((uVar14 & 8) == 0) {
                iVar7 = 2;
              }
              else {
                cStack_21d = '\x01';
                iVar7 = 1;
              }
            }
            iStack_248 = iStack_248 + iVar7;
            if (iVar8 == 2) goto LAB_00550d58;
            if ((char)abStack_210[2] < '\0') {
              uVar14 = _Var12.boolean & 4;
LAB_0055156c:
              if ((uVar14 & 6) == 0) {
                iVar7 = 2;
                if (abStack_210[2] != 0x5c) {
                  iVar7 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_208,0xb,"\\%02X");
                iVar7 = 3;
              }
            }
            else {
              uVar14 = uVar13 & (byte)char_type[abStack_210[2]];
              if ((uVar14 & 0x61) == 0) goto LAB_0055156c;
              if ((uVar14 & 8) == 0) {
                iVar7 = 2;
              }
              else {
                iVar7 = 1;
                cStack_21d = '\x01';
              }
            }
            iStack_248 = iStack_248 + iVar7;
            if (iVar8 == 3) goto LAB_00550d58;
            if ((char)abStack_210[3] < '\0') {
              uVar14 = _Var12.boolean & 4;
LAB_00551548:
              if ((uVar14 & 6) == 0) {
                iVar7 = 2;
                if (abStack_210[3] != 0x5c) {
                  iVar7 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_208,0xb,"\\%02X");
                iVar7 = 3;
              }
            }
            else {
              uVar14 = uVar13 & (byte)char_type[abStack_210[3]];
              if ((uVar14 & 0x61) == 0) goto LAB_00551548;
              if ((uVar14 & 8) == 0) {
                iVar7 = 2;
              }
              else {
                iVar7 = 1;
                cStack_21d = '\x01';
              }
            }
            iStack_248 = iStack_248 + iVar7;
            if (iVar8 == 4) goto LAB_00550d58;
            if ((char)bStack_20c < '\0') {
              uVar14 = _Var12.boolean & 4;
LAB_00551524:
              if ((uVar14 & 6) == 0) {
                iVar7 = 2;
                if (bStack_20c != 0x5c) {
                  iVar7 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_208,0xb,"\\%02X");
                iVar7 = 3;
              }
            }
            else {
              uVar14 = uVar13 & (byte)char_type[bStack_20c];
              if ((uVar14 & 0x61) == 0) goto LAB_00551524;
              if ((uVar14 & 8) == 0) {
                iVar7 = 2;
              }
              else {
                iVar7 = 1;
                cStack_21d = '\x01';
              }
            }
            iStack_248 = iStack_248 + iVar7;
            if (iVar8 != 5) {
              if ((char)bStack_20b < '\0') {
                uVar13 = _Var12.boolean & 4;
              }
              else {
                uVar13 = uVar13 & (byte)char_type[bStack_20b];
                if ((uVar13 & 0x61) != 0) goto LAB_00550d40;
              }
              iVar8 = 1;
              if ((uVar13 & 6) != 0) goto LAB_00551448;
              if (bStack_20b == 0x5c) {
                iVar8 = 2;
              }
              iStack_248 = iStack_248 + iVar8;
            }
          }
        }
      }
LAB_00550d58:
    } while (pBVar22 != pBVar19);
  }
  iStack_248 = uStack_244 + iStack_248;
  if (cStack_21d == '\0') {
    iVar8 = iStack_248;
    if (a == (ASN1_TYPE *)0x0) goto LAB_00550988;
  }
  else {
    iStack_248 = iStack_248 + 2;
    iVar8 = iStack_248;
    if (a == (ASN1_TYPE *)0x0) goto LAB_00550988;
    iVar8 = (*(code *)PTR_BIO_write_006a7f14)(a,&DAT_0067a4c0,1);
    if (iVar8 != 1) goto LAB_00550980;
  }
  psVar16 = (stack_st_X509_NAME_ENTRY *)(_Var9.object)->sn;
  pBVar22 = (BUF_MEM *)(_Var9.asn1_string)->data;
  pBVar18 = (BUF_MEM *)((int)&pBVar22->length + (int)psVar16);
  if (pBVar22 != pBVar18) {
    _Var9.boolean = uVar15 & 7;
    uStack_244 = uVar15 & 8;
    pBVar19 = pBVar22;
    do {
      while( true ) {
        if (pBVar19 == pBVar22) {
          uVar15 = 0x20;
          if ((_Var12.boolean & 1U) == 0) {
            uVar15 = 0;
          }
        }
        else {
          uVar15 = 0;
        }
        if ((X509_NAME *)_Var9.ptr == (X509_NAME *)0x1) {
          AStack_218.type = (int)*(byte *)&pBVar19->length;
          pBVar19 = (BUF_MEM *)((int)&pBVar19->length + 1);
        }
        else if ((uint)_Var9 < (X509_NAME *)0x2) {
          if (((X509_NAME *)_Var9.ptr != (X509_NAME *)0x0) ||
             (iVar8 = (*(code *)PTR_UTF8_getc_006a9df0)(pBVar19,psVar16,&AStack_218), iVar8 < 0))
          goto LAB_00550980;
          pBVar19 = (BUF_MEM *)((int)&pBVar19->length + iVar8);
        }
        else if ((X509_NAME *)_Var9.ptr == (X509_NAME *)&SUB_00000002) {
          AStack_218.type = (int)*(ushort *)&pBVar19->length;
          pBVar19 = (BUF_MEM *)((int)&pBVar19->length + 2);
        }
        else {
          iVar8 = -1;
          if ((X509_NAME *)_Var9.ptr != (X509_NAME *)&SUB_00000004) goto LAB_00550988;
          AStack_218.type =
               (uint)*(byte *)((int)&pBVar19->length + 3) |
               (uint)*(byte *)((int)&pBVar19->length + 2) << 8 |
               (uint)*(byte *)((int)&pBVar19->length + 1) << 0x10 |
               (uint)*(byte *)&pBVar19->length << 0x18;
          pBVar19 = (BUF_MEM *)&pBVar19->data;
        }
        if ((pBVar18 == pBVar19) && ((_Var12.boolean & 1U) != 0)) {
          uVar15 = 0x40;
        }
        if (uStack_244 != 0) break;
        iVar8 = do_esc_char_constprop_6(AStack_218.type,uVar11 | uVar15,0,a);
        if (iVar8 < 0) goto LAB_00550980;
        if (pBVar18 == pBVar19) goto LAB_00550f3c;
      }
      pbVar25 = abStack_210;
      iVar8 = (*(code *)PTR_UTF8_putc_006a9dec)(pbVar25,6,AStack_218.type);
      if (0 < iVar8) {
        pbVar21 = pbVar25 + iVar8;
        do {
          while( true ) {
            bVar1 = *pbVar25;
            _Stack_21c.boolean = _Stack_21c.boolean & 0xffffffU | (uint)bVar1 << 0x18;
            if ((char)bVar1 < '\0') break;
            uVar23 = (uVar11 | uVar15) & (uint)(byte)char_type[bVar1];
            if ((uVar23 & 0x61) == 0) goto LAB_00550f78;
            if ((uVar23 & 8) == 0) {
              iVar8 = (*(code *)PTR_BIO_write_006a7f14)(a,&DAT_0066a048,1);
              if (iVar8 != 1) goto LAB_00550980;
              iVar8 = (*(code *)PTR_BIO_write_006a7f14)(a,&_Stack_21c,1);
            }
            else {
LAB_00550f08:
              iVar8 = (*(code *)PTR_BIO_write_006a7f14)(a,&_Stack_21c,1);
            }
            if (iVar8 != 1) goto LAB_00550980;
joined_r0x00551128:
            pbVar25 = pbVar25 + 1;
            if (pbVar21 == pbVar25) goto LAB_00550f30;
          }
          uVar23 = _Var12.boolean & 4;
LAB_00550f78:
          if ((uVar23 & 6) == 0) {
            if ((bVar1 != 0x5c) || (uVar11 == 0)) goto LAB_00550f08;
            iVar8 = (*(code *)PTR_BIO_write_006a7f14)(a,&DAT_0066a054,2);
            if (iVar8 == 2) goto joined_r0x00551128;
            goto LAB_00550980;
          }
          (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_208,0xb,"\\%02X");
          iVar8 = (*(code *)PTR_BIO_write_006a7f14)(a,&cStack_208,3);
          if (iVar8 != 3) goto LAB_00550980;
          pbVar25 = pbVar25 + 1;
        } while (pbVar21 != pbVar25);
      }
LAB_00550f30:
    } while (pBVar18 != pBVar19);
  }
LAB_00550f3c:
  iVar8 = iStack_248;
  if (cStack_21d == '\0') goto LAB_00550988;
  iVar7 = (*(code *)PTR_BIO_write_006a7f14)(a,&DAT_0067a4c0,1);
  if (iVar7 == 1) goto LAB_00550988;
LAB_00550980:
  do {
    iVar8 = -1;
LAB_00550988:
    while( true ) {
      if (iStack_1fc == *(int *)puVar2) {
        return iVar8;
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00551874:
      AStack_218.type = (_Var9.asn1_string)->type;
      AStack_218.value = _Var9;
      iVar8 = i2d_ASN1_TYPE(&AStack_218,(uchar **)0x0);
      _Var9.ptr = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar8,"a_strex.c",0x119);
      if ((X509_NAME *)_Var9.ptr == (X509_NAME *)0x0) break;
      _Stack_21c.ptr = _Var9.ptr;
      i2d_ASN1_TYPE(&AStack_218,(uchar **)&_Stack_21c.ptr);
      if ((X509_NAME *)(_Var9.ptr + iVar8) != (X509_NAME *)_Var9.ptr) {
        _Var12.ptr = _Var9.ptr;
        do {
          cStack_208 = "0123456789ABCDEF"[(byte)*_Var12.ptr >> 4];
          cStack_207 = "0123456789ABCDEF"[(byte)*_Var12.ptr & 0xf];
          iVar7 = (*(code *)PTR_BIO_write_006a7f14)(a,&cStack_208,2);
          if (iVar7 != 2) {
            (*(code *)PTR_CRYPTO_free_006a7f88)(_Var9.ptr);
            goto LAB_00550980;
          }
          _Var12.ptr = (char *)((int)&(_Var12.asn1_string)->length + 1);
        } while ((X509_NAME *)(_Var9.ptr + iVar8) != (X509_NAME *)_Var12.ptr);
      }
LAB_00551724:
      a = (ASN1_TYPE *)(iVar8 * 2);
      (*(code *)PTR_CRYPTO_free_006a7f88)(_Var9.ptr);
      if ((int)a < 0) break;
      iVar8 = (int)&a->type + uStack_244 + 1;
    }
  } while( true );
}

