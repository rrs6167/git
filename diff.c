static char *run_textconv(const char *, struct diff_filespec *, size_t *);
	FILE *file;
static void emit_line_0(FILE *file, const char *set, const char *reset,
static void emit_line(FILE *file, const char *set, const char *reset,
	emit_line_0(file, set, reset, line[0], line+1, len-1);
		emit_line_0(ecbdata->file, set, reset, '+', line, len);
		emit_line_0(ecbdata->file, ws, reset, '+', line, len);
		emit_line_0(ecbdata->file, set, reset, '+', "", 0);
			      ecbdata->file, set, reset, ws);
		emit_line(ecbdata->file, plain, reset, line, len);
	emit_line(ecbdata->file, frag, reset, line, ep - line);
	if (ep != cp)
		emit_line(ecbdata->file, plain, reset, cp, ep - cp);
	if (ep < line + len)
		emit_line(ecbdata->file, func, reset, ep, line + len - ep);
			emit_line_0(ecb->file, old, reset, '-',
		emit_line_0(ecb->file, plain, reset, '\\',
			      const char *textconv_one,
			      const char *textconv_two,
	const char *data_one, *data_two;
	diff_populate_filespec(one, 0);
	diff_populate_filespec(two, 0);
	if (textconv_one) {
		data_one = run_textconv(textconv_one, one, &size_one);
		if (!data_one)
			die("unable to read files to diff");
	}
	else {
		data_one = one->data;
		size_one = one->size;
	}
	if (textconv_two) {
		data_two = run_textconv(textconv_two, two, &size_two);
		if (!data_two)
			die("unable to read files to diff");
	}
	else {
		data_two = two->data;
		size_two = two->size;
	}
	ecbdata.file = o->file;
		"%s--- %s%s%s\n%s+++ %s%s%s\n%s@@ -",
		metainfo, a_name.buf, name_a_tab, reset,
		metainfo, b_name.buf, name_b_tab, reset, fraginfo);
	FILE *file;
	if (diff_words->current_plus != plus_begin)
		fwrite(diff_words->current_plus,
				plus_begin - diff_words->current_plus, 1,
				diff_words->file);
	if (minus_begin != minus_end)
		color_fwrite_lines(diff_words->file,
				diff_get_color(1, DIFF_FILE_OLD),
				minus_end - minus_begin, minus_begin);
	if (plus_begin != plus_end)
		color_fwrite_lines(diff_words->file,
				diff_get_color(1, DIFF_FILE_NEW),
				plus_end - plus_begin, plus_begin);
		color_fwrite_lines(diff_words->file,
			diff_get_color(1, DIFF_FILE_OLD),
			diff_words->minus.text.size, diff_words->minus.text.ptr);
			diff_words->plus.text.size)
		fwrite(diff_words->current_plus,
			- diff_words->current_plus, 1,
			diff_words->file);
		fprintf(ecbdata->file, "%s", ecbdata->header->buf);
		fprintf(ecbdata->file, "%s--- %s%s%s\n",
			meta, ecbdata->label_path[0], reset, name_a_tab);
		fprintf(ecbdata->file, "%s+++ %s%s%s\n",
			meta, ecbdata->label_path[1], reset, name_b_tab);
			putc('\n', ecbdata->file);
		emit_line(ecbdata->file, reset, reset, line, len);
		line++;
		len--;
		emit_line(ecbdata->file, plain, reset, line, len);
		emit_line(ecbdata->file, color, reset, line, len);
static long gather_dirstat(FILE *file, struct dirstat_dir *dir, unsigned long changed, const char *base, int baselen)
			this = gather_dirstat(file, dir, changed, f->name, newbaselen);
				fprintf(file, "%4d.%01d%% %.*s\n", percent, permille % 10, baselen, base);
	gather_dirstat(options->file, &dir, changed, "", 0);
				"%s:%d: leftover conflict marker\n",
				data->filename, data->lineno);
		fprintf(data->o->file, "%s:%d: %s.\n",
			data->filename, data->lineno, err);
		emit_line(data->o->file, set, reset, line, 1);
static void emit_binary_diff_body(FILE *file, mmfile_t *one, mmfile_t *two)
		fprintf(file, "delta %lu\n", orig_size);
		fprintf(file, "literal %lu\n", two->size);
	fprintf(file, "\n");
static void emit_binary_diff(FILE *file, mmfile_t *one, mmfile_t *two)
	fprintf(file, "GIT binary patch\n");
	emit_binary_diff_body(file, one, two);
	emit_binary_diff_body(file, two, one);
static const char *get_textconv(struct diff_filespec *one)
	return one->driver->textconv;
	const char *textconv_one = NULL, *textconv_two = NULL;
	strbuf_addf(&header, "%sdiff --git %s %s%s\n", set, a_one, b_two, reset);
		strbuf_addf(&header, "%snew file mode %06o%s\n", set, two->mode, reset);
		strbuf_addf(&header, "%sdeleted file mode %06o%s\n", set, one->mode, reset);
			strbuf_addf(&header, "%sold mode %06o%s\n", set, one->mode, reset);
			strbuf_addf(&header, "%snew mode %06o%s\n", set, two->mode, reset);
	if (fill_mmfile(&mf1, one) < 0 || fill_mmfile(&mf2, two) < 0)
		die("unable to read files to diff");

	    ( (diff_filespec_is_binary(one) && !textconv_one) ||
	      (diff_filespec_is_binary(two) && !textconv_two) )) {
		    !memcmp(mf1.ptr, mf2.ptr, mf1.size))
			emit_binary_diff(o->file, &mf1, &mf2);
			fprintf(o->file, "Binary files %s and %s differ\n",
				lbl[0], lbl[1]);
		if (!DIFF_XDL_TST(o, WHITESPACE_FLAGS)) {
		if (textconv_one) {
			size_t size;
			mf1.ptr = run_textconv(textconv_one, one, &size);
			if (!mf1.ptr)
				die("unable to read files to diff");
			mf1.size = size;
		}
		if (textconv_two) {
			size_t size;
			mf2.ptr = run_textconv(textconv_two, two, &size);
			if (!mf2.ptr)
				die("unable to read files to diff");
			mf2.size = size;
		}
		ecbdata.file = o->file;
		if (DIFF_OPT_TST(o, COLOR_DIFF_WORDS)) {
			ecbdata.diff_words->file = o->file;
		if (DIFF_OPT_TST(o, COLOR_DIFF_WORDS))
		strbuf_addf(msg, "%ssimilarity index %d%%",
			    set, similarity_index(p));
		strbuf_addf(msg, "%s\n%scopy from ", reset, set);
		strbuf_addf(msg, "%s\n%scopy to ", reset, set);
		strbuf_addf(msg, "%ssimilarity index %d%%",
			    set, similarity_index(p));
		strbuf_addf(msg, "%s\n%srename from ", reset, set);
		strbuf_addf(msg, "%s\n%srename to ", reset, set);
			strbuf_addf(msg, "%sdissimilarity index %d%%%s\n",
		;
		strbuf_addf(msg, "%sindex %.*s..%.*s", set,
			    abbrev, sha1_to_hex(one->sha1),
			    abbrev, sha1_to_hex(two->sha1));
			     one, two, xfrm_msg, o, complete_rewrite);
	if (!diff_mnemonic_prefix) {
	if (!strcmp(arg, "-p") || !strcmp(arg, "-u"))
		DIFF_OPT_SET(options, COLOR_DIFF_WORDS);
		DIFF_OPT_SET(options, COLOR_DIFF_WORDS);
static void show_mode_change(FILE *file, struct diff_filepair *p, int show_name)
		fprintf(file, " mode change %06o => %06o%c", p->one->mode, p->two->mode,
			show_name ? ' ' : '\n');
static void show_rename_copy(FILE *file, const char *renamecopy, struct diff_filepair *p)
	show_mode_change(file, p, 0);
static void diff_summary(FILE *file, struct diff_filepair *p)
		show_rename_copy(file, "copy", p);
		show_rename_copy(file, "rename", p);
			fputs(" rewrite ", file);
		show_mode_change(file, p, !p->score);
	q->queue = NULL;
	q->nr = q->alloc = 0;
		for (i = 0; i < q->nr; i++)
			diff_summary(options->file, q->queue[i]);
	q->queue = NULL;
	q->nr = q->alloc = 0;
	outq.queue = NULL;
	outq.nr = outq.alloc = 0;
	outq.queue = NULL;
	outq.nr = outq.alloc = 0;