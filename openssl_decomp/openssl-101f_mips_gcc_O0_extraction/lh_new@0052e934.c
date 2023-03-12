
_LHASH * lh_new(LHASH_HASH_FN_TYPE h,LHASH_COMP_FN_TYPE c)

{
  undefined *puVar1;
  _LHASH *p_Var2;
  LHASH_NODE **ppLVar3;
  
  p_Var2 = (_LHASH *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x60,"lhash.c",0x77);
  if (p_Var2 == (_LHASH *)0x0) {
    p_Var2 = (_LHASH *)0x0;
  }
  else {
    ppLVar3 = (LHASH_NODE **)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x40,"lhash.c",0x79);
    p_Var2->b = ppLVar3;
    if (ppLVar3 == (LHASH_NODE **)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)(p_Var2);
      p_Var2 = (_LHASH *)0x0;
    }
    else {
      *ppLVar3 = (LHASH_NODE *)0x0;
      puVar1 = PTR_strcmp_006aac20;
      p_Var2->b[1] = (LHASH_NODE *)0x0;
      if (c == (LHASH_COMP_FN_TYPE)0x0) {
        c = (LHASH_COMP_FN_TYPE)puVar1;
      }
      p_Var2->b[2] = (LHASH_NODE *)0x0;
      p_Var2->b[3] = (LHASH_NODE *)0x0;
      p_Var2->b[4] = (LHASH_NODE *)0x0;
      p_Var2->b[5] = (LHASH_NODE *)0x0;
      p_Var2->b[6] = (LHASH_NODE *)0x0;
      p_Var2->b[7] = (LHASH_NODE *)0x0;
      p_Var2->b[8] = (LHASH_NODE *)0x0;
      p_Var2->b[9] = (LHASH_NODE *)0x0;
      p_Var2->b[10] = (LHASH_NODE *)0x0;
      p_Var2->b[0xb] = (LHASH_NODE *)0x0;
      p_Var2->b[0xc] = (LHASH_NODE *)0x0;
      p_Var2->b[0xd] = (LHASH_NODE *)0x0;
      p_Var2->b[0xe] = (LHASH_NODE *)0x0;
      p_Var2->b[0xf] = (LHASH_NODE *)0x0;
      p_Var2->comp = c;
      if (h == (LHASH_HASH_FN_TYPE)0x0) {
        h = lh_strhash;
      }
      p_Var2->hash = h;
      p_Var2->p = 0;
      p_Var2->num_items = 0;
      p_Var2->num_nodes = 8;
      p_Var2->pmax = 8;
      p_Var2->num_alloc_nodes = 0x10;
      p_Var2->num_expands = 0;
      p_Var2->up_load = 0x200;
      p_Var2->num_expand_reallocs = 0;
      p_Var2->num_contracts = 0;
      p_Var2->down_load = 0x100;
      p_Var2->num_contract_reallocs = 0;
      p_Var2->num_hash_calls = 0;
      p_Var2->num_comp_calls = 0;
      p_Var2->num_insert = 0;
      p_Var2->num_replace = 0;
      p_Var2->num_delete = 0;
      p_Var2->num_no_delete = 0;
      p_Var2->num_retrieve = 0;
      p_Var2->num_retrieve_miss = 0;
      p_Var2->num_hash_comps = 0;
      p_Var2->error = 0;
    }
  }
  return p_Var2;
}

