
void lh_stats_bio(_LHASH *lh,BIO *out)

{
  undefined4 in_r3;
  
  BIO_printf(out,"num_items             = %lu\n",lh->num_items);
  BIO_printf(out,"num_nodes             = %u\n",lh->num_nodes);
  BIO_printf(out,"num_alloc_nodes       = %u\n",lh->num_alloc_nodes);
  BIO_printf(out,"num_expands           = %lu\n",lh->num_expands);
  BIO_printf(out,"num_expand_reallocs   = %lu\n",lh->num_expand_reallocs);
  BIO_printf(out,"num_contracts         = %lu\n",lh->num_contracts);
  BIO_printf(out,"num_contract_reallocs = %lu\n",lh->num_contract_reallocs);
  BIO_printf(out,"num_hash_calls        = %lu\n",lh->num_hash_calls);
  BIO_printf(out,"num_comp_calls        = %lu\n",lh->num_comp_calls);
  BIO_printf(out,"num_insert            = %lu\n",lh->num_insert);
  BIO_printf(out,"num_replace           = %lu\n",lh->num_replace);
  BIO_printf(out,"num_delete            = %lu\n",lh->num_delete);
  BIO_printf(out,"num_no_delete         = %lu\n",lh->num_no_delete);
  BIO_printf(out,"num_retrieve          = %lu\n",lh->num_retrieve);
  BIO_printf(out,"num_retrieve_miss     = %lu\n",lh->num_retrieve_miss);
  BIO_printf(out,"num_hash_comps        = %lu\n",lh->num_hash_comps,in_r3);
  return;
}

