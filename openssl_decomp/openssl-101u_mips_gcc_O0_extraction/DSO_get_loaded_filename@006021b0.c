
char * DSO_get_loaded_filename(DSO *dso)

{
  if (dso != (DSO *)0x0) {
    return dso->loaded_filename;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x80,0x43,"dso_lib.c",0x1a3);
  return (char *)0x0;
}

