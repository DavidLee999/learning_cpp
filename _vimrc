source $VIMRUNTIME/vimrc_example.vim
source $VIMRUNTIME/mswin.vim
behave mswin

"插件管理
filetype off
set nocompatible
set rtp+=$VIM/vimfiles/bundle/Vundle.vim
call vundle#begin('$VIM/vimfiles/bundle')
"let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
"my bundle plugin
Plugin 'Raimondi/delimitMate.git'
Bundle 'ShowTrailingWhitespace'
Bundle 'OmniCppComplete'
Bundle 'a.vim'
Bundle 'Mizuchi/STL-Syntax'
Bundle 'majutsushi/tagbar'
Bundle 'scrooloose/nerdtree'
Bundle 'bling/vim-airline'
Bundle 'davidhalter/jedi-vim'
Bundle 'nathanaelkane/vim-indent-guides'
Bundle 'SirVer/ultisnips'
call vundle#end()
filetype plugin indent on

set nu!
set guifont=consolas:h14
colo corporation
"colo solarized
set lines=45 columns=118
syntax enable
syntax on
set expandtab
set showmatch
set smartindent
set shiftwidth=4
set autoindent
set ai!
set tabstop=4
set noundofile
set nobackup
set noswapfile
set cursorline
set cursorcolumn
set softtabstop=4
set diffexpr=MyDiff()
let Tlist_Auto_Open=0
set tags=.\tags;
set tags+=C:\stl_tags;
set showtabline=2

set autochdir
" 随 vim 自启动
let g:indent_guides_enable_on_vim_startup=1
" 从第二层开始可视化显示缩进
let g:indent_guides_start_level=2
" 色块宽度
let g:indent_guides_guide_size=1

let OmniCpp_GlobalScopeSearch=1
let OmniCpp_NamespaceSearch=1
let OmniCpp_DisplayMode=1
let OmniCpp_ShowScopeInAbbr=0
let OmniCpp_ShowPrototypeInAbbr=1
let OmniCpp_MayCompleteDot=1 
let OmniCpp_MayCompleteArrow=1
let OmniCpp_MayCompleteScope=1
let OmniCpp_DefaultNamespaces=["std", "_GLIBCXX_STD"]
au CursorMovedI,InsertLeave * if pumvisible() == 0|silent! pclose|endif
set completeopt=menuone,menu,longest

map <C-F11> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<CR> 
noremap <F11> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<cr> 
inoremap <F11> <Esc>:!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<cr> 

highlight Pmenu    guibg=darkgrey  guifg=black
highlight PmenuSel guibg=lightgrey guifg=black

"设置tagbar使用的ctags的插件,必须要设置对
let g:tagbar_ctags_bin='ctags'
"设置tagbar的窗口宽度
let g:tagbar_width=30
"设置tagbar的窗口显示的位置,为左边
let g:tagbar_left=1
"打开文件自动 打开tagbar
autocmd BufReadPost *.cpp,*.c,*.h,*.hpp,*.cc,*.cxx call tagbar#autoopen()
"映射tagbar的快捷键
map <F8> :TagbarToggle<CR>

let NERDTreeWinPos='right'
let NERDTreeWinSize=30
map <F2> :NERDTreeToggle<CR>

set laststatus=2

let g:UltiSnipsSnippetDirectories=['mysnips']

"定义CompileRun函数，用来调用进行编译和运行
func CompileRun()
	exec "w"
	"C程序
		if &filetype == 'c'
			exec "!gcc % -o %<"
	"c++程序
		elseif &filetype == 'cpp'
			exec "!g++ -W -Wall % -g -o %< -std=c++11"
	"Java程序
		elseif &filetype == 'java'
			exec "!javac %"
		endif
endfunc
"结束定义CompileRun

"定义Run函数
func Run()
	if &filetype == 'c' || &filetype == 'cpp'
		exec "!%<.exe"
	elseif &filetype == 'java'
		exec "!java %<"
	elseif &filetype == 'python'
		exec "!py -3 %"
	endif
endfunc

"定义Run函数
func RunPython2()	
	if &filetype == 'python'
		exec "!py -2 %"
	endif
endfunc

map <c-r> :call CompileRun()<CR>
map <F5> :call Run()<CR>
map <c-p> :call RunPython2()<CR>


function MyDiff()
  let opt = '-a --binary '
  if &diffopt =~ 'icase' | let opt = opt . '-i ' | endif
  if &diffopt =~ 'iwhite' | let opt = opt . '-b ' | endif
  let arg1 = v:fname_in
  if arg1 =~ ' ' | let arg1 = '"' . arg1 . '"' | endif
  let arg2 = v:fname_new
  if arg2 =~ ' ' | let arg2 = '"' . arg2 . '"' | endif
  let arg3 = v:fname_out
  if arg3 =~ ' ' | let arg3 = '"' . arg3 . '"' | endif
  if $VIMRUNTIME =~ ' '
    if &sh =~ '\<cmd'
      if empty(&shellxquote)
        let l:shxq_sav = ''
        set shellxquote&
      endif
      let cmd = '"' . $VIMRUNTIME . '\diff"'
    else
      let cmd = substitute($VIMRUNTIME, ' ', '" ', '') . '\diff"'
    endif
  else
    let cmd = $VIMRUNTIME . '\diff'
  endif
  silent execute '!' . cmd . ' ' . opt . arg1 . ' ' . arg2 . ' > ' . arg3
  if exists('l:shxq_sav')
    let &shellxquote=l:shxq_sav
  endif
endfunction

