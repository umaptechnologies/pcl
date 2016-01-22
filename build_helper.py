def insert_target_in_libs(target, libs):
    adjusted_libs = []
    for lib in libs:
        adjusted_lib = lib
        if adjusted_lib.startswith('TARGET'):
            adjusted_lib = '%s_%s' % (target, adjusted_lib[6:])
        adjusted_libs.append(adjusted_lib)

    return adjusted_libs

def set_build_directory(VariantDir, build_dir, sources):
    VariantDir(build_dir, '.')
    
    adjusted_sources = []
    for source in sources:
        adjusted_sources.append('%s/%s' % (build_dir, source))

    return adjusted_sources
