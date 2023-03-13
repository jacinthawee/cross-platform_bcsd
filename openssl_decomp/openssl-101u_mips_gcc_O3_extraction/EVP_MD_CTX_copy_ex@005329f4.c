
int EVP_MD_CTX_copy_ex(EVP_MD_CTX *out,EVP_MD_CTX *in)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  EVP_MD *pEVar21;
  EVP_PKEY_CTX *pEVar22;
  EVP_MD_CTX *pEVar23;
  uint in_a2;
  ulong uVar24;
  uint in_t0;
  uint in_t1;
  void *pvVar25;
  _func_1081 *UNRECOVERED_JUMPTABLE;
  
  if ((in == (EVP_MD_CTX *)0x0) || (pEVar21 = in->digest, pEVar21 == (EVP_MD *)0x0)) {
    ERR_put_error(6,0x6e,0x6f,"digest.c",0x122);
    return 0;
  }
  pEVar23 = in;
  if (in->engine != (ENGINE *)0x0) {
    iVar20 = ENGINE_init(in->engine);
    if (iVar20 == 0) {
      ERR_put_error(6,0x6e,0x26,"digest.c",0x128);
      return 0;
    }
    pEVar21 = in->digest;
  }
  pvVar25 = (void *)0x0;
  if (out->digest == pEVar21) {
    pEVar23 = (EVP_MD_CTX *)&SUB_00000004;
    pvVar25 = out->md_data;
    EVP_MD_CTX_set_flags(out,4);
  }
  EVP_MD_CTX_cleanup(out);
  uVar3 = (uint)in & 3;
  uVar4 = (uint)&in->engine & 3;
  iVar20 = *(int *)((int)&in->engine - uVar4);
  uVar24 = in->flags;
  uVar5 = (uint)&in->md_data & 3;
  iVar8 = *(int *)((int)&in->md_data - uVar5);
  uVar6 = (uint)&in->pctx & 3;
  iVar9 = *(int *)((int)&in->pctx - uVar6);
  uVar7 = (uint)&in->update & 3;
  iVar10 = *(int *)((int)&in->update - uVar7);
  puVar1 = (undefined *)((int)&in->digest + 3);
  uVar11 = (uint)puVar1 & 3;
  puVar2 = (undefined *)((int)&in->engine + 3);
  uVar12 = (uint)puVar2 & 3;
  uVar16 = *(uint *)(puVar2 + -uVar12);
  puVar2 = (undefined *)((int)&in->md_data + 3);
  uVar13 = (uint)puVar2 & 3;
  uVar17 = *(uint *)(puVar2 + -uVar13);
  puVar2 = (undefined *)((int)&in->pctx + 3);
  uVar14 = (uint)puVar2 & 3;
  uVar18 = *(uint *)(puVar2 + -uVar14);
  puVar2 = (undefined *)((int)&in->update + 3);
  uVar15 = (uint)puVar2 & 3;
  uVar19 = *(uint *)(puVar2 + -uVar15);
  out->digest = (EVP_MD *)
                ((*(int *)((int)in - uVar3) << uVar3 * 8 | in_t1 & 0xffffffffU >> (4 - uVar3) * 8) &
                 -1 << (uVar11 + 1) * 8 | *(uint *)(puVar1 + -uVar11) >> (3 - uVar11) * 8);
  out->engine = (ENGINE *)
                ((iVar20 << uVar4 * 8 | in_t0 & 0xffffffffU >> (4 - uVar4) * 8) &
                 -1 << (uVar12 + 1) * 8 | uVar16 >> (3 - uVar12) * 8);
  out->flags = uVar24;
  out->md_data = (void *)((iVar8 << uVar5 * 8 | in_a2 & 0xffffffffU >> (4 - uVar5) * 8) &
                          -1 << (uVar13 + 1) * 8 | uVar17 >> (3 - uVar13) * 8);
  out->pctx = (EVP_PKEY_CTX *)
              ((iVar9 << uVar6 * 8 | (uint)pEVar23 & 0xffffffffU >> (4 - uVar6) * 8) &
               -1 << (uVar14 + 1) * 8 | uVar18 >> (3 - uVar14) * 8);
  out->update = (_func_1088 *)
                ((iVar10 << uVar7 * 8 | (uint)pEVar21 & 0xffffffffU >> (4 - uVar7) * 8) &
                 -1 << (uVar15 + 1) * 8 | uVar19 >> (3 - uVar15) * 8);
  if ((in->md_data != (void *)0x0) && (iVar20 = out->digest->ctx_size, iVar20 != 0)) {
    if (pvVar25 == (void *)0x0) {
      pvVar25 = (void *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar20,"digest.c",0x139);
      out->md_data = pvVar25;
      if (pvVar25 == (void *)0x0) {
        ERR_put_error(6,0x6e,0x41,"digest.c",0x13b);
        return 0;
      }
      iVar20 = out->digest->ctx_size;
    }
    else {
      out->md_data = pvVar25;
    }
    (*(code *)PTR_memcpy_006a9aec)(pvVar25,in->md_data,iVar20);
  }
  pEVar22 = in->pctx;
  out->update = in->update;
  if (pEVar22 != (EVP_PKEY_CTX *)0x0) {
    pEVar22 = EVP_PKEY_CTX_dup(pEVar22);
    out->pctx = pEVar22;
    if (pEVar22 == (EVP_PKEY_CTX *)0x0) {
      EVP_MD_CTX_cleanup(out);
      return 0;
    }
  }
  UNRECOVERED_JUMPTABLE = out->digest->copy;
  if (UNRECOVERED_JUMPTABLE == (_func_1081 *)0x0) {
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x00532b48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar20 = (*UNRECOVERED_JUMPTABLE)(out,in);
  return iVar20;
}

