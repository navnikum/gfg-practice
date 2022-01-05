"use strict";

import { DataFilter } from '@oracle/oraclejet/dist/types/ojdataprovider';
import { ojTable } from '@oracle/oraclejet/dist/types/ojtable';
import * as ko from "knockout";
import * as componentStrings from 'ojL10n!oj-spectra/shared/resources/nls/oj-spectra-strings';
import 'ojs/ojbutton';
import Context = require("ojs/ojcontext");
import Composite = require("ojs/ojcomposite");
import 'ojs/ojinputtext';
import "ojs/ojknockout";
import ListDataProviderView = require('ojs/ojlistdataproviderview');
import Logger = require('ojs/ojlogger');
import 'ojs/ojtable';

export default class ViewModel
  implements Composite.ViewModel<Composite.PropertiesType>
{
  busyResolve: () => void;
  composite: Element;
  public columnData: Array<{ [key: string]: string }> = [];
  public dataProvider: ko.Computed<any>;
  public mainTitle: ko.Observable<string>;
  properties: Composite.PropertiesType;
  public handleValueChanged: Function;
  res: { [key: string]: string };
  public searchTerm: ko.Observable<string> = ko.observable('');
  public uid: string;

  constructor(context: Composite.ViewModelContext<Composite.PropertiesType>) {
    //At the start of your viewModel constructor
    const elementContext: Context = Context.getContext(context.element);
    const busyContext: Context.BusyContext = elementContext.getBusyContext();
    const options = { description: "Web Component Startup - Waiting for data" };
    this.busyResolve = busyContext.addBusyState(options);

    this.composite = context.element;
    this.uid = context.uniqueId;

    //Example observable
    this.properties = context.properties;
    Logger.log('input properties:');
    Logger.log(this.properties);

    this.res = { ...componentStrings['oj-spectra-sample1'], ...this.properties.translations };

    // Example for parsing context properties
    // if (context.properties.name) {
    //     parse the context properties here
    // }
    if (this.properties.mainTitle) {
      this.mainTitle = ko.observable(this.properties.mainTitle);
    }
    if (this.properties.searchTerm) {
      this.searchTerm = ko.observable(this.properties.searchTerm);
    }
    
    if (this.properties.column) {
      for (let i: number = 0; i < this.properties.column.length; i++) {
        const item: { [key: string]: string } = this.properties.column[i];
        item.renderer = this.highlighter.bind(this, this);
        item.resizable = 'enabled';
        this.columnData.push(item);
      }
    }
    if (this.properties.data) {
      this.dataProvider = ko.computed(() => {
        const filterRegEx: RegExp = new RegExp(this.searchTerm(), 'i');
        const criteria: Array<{ op: string; value: any }> = [];
        for (const col of this.columnData) {
          const val: { [key: string]: RegExp } = {};
          val[col.field] = filterRegEx;
          criteria.push({ op: '$regex', value: val });
        }
        const filterCriterion: any = {
          criteria,
          op: '$or',
        };
        return new ListDataProviderView(this.properties.data, { filterCriterion });
      }, this);
    }
    
    this.handleValueChanged = (event: CustomEvent, self: ViewModel) => {
      const searchInput: any = event.target;
      if (searchInput) {
        self.searchTerm(searchInput.rawValue);
      }
    };

    //Once all startup and async activities have finished, relocate if there are any async activities
    this.busyResolve();
  }

  public highlighter(self: ViewModel, context: ojTable.ColumnsRendererContext<string, any>): void {
    let data: string = context.row[self.columnData[context.columnIndex].field].toString();
    const filterString: string = self.searchTerm();
    if (filterString && filterString.length > 0) {
      const index: number = data.toLowerCase().indexOf(filterString.toLowerCase());
      if (index > -1) {
        const highlightedSegment: string = data.substr(index, filterString.length);
        data = data.substr(0, index) + '<b><u>' + highlightedSegment + '</u></b>' + data.substr(index + filterString.length, data.length - 1);
      }
    }
    context.parentElement.innerHTML = data;
  }
  
  //Lifecycle methods - implement if necessary

  activated(
    context: Composite.ViewModelContext<Composite.PropertiesType>
  ): Promise<any> | void {
    Logger.log(`%c CCA ${this.uid} activated`, 'background: #222; color: #bada55');
  }

  connected(
    context: Composite.ViewModelContext<Composite.PropertiesType>
  ): void {
    Logger.log(`%c CCA ${this.uid} connected`, 'background: #222; color: #bada55');
  }

  bindingsApplied(
    context: Composite.ViewModelContext<Composite.PropertiesType>
  ): void {
    Logger.log(`%c CCA ${this.uid} bindingsApplied`, 'background: #222; color: #bada55');
  }

  propertyChanged(
    context: Composite.PropertyChangedContext<Composite.PropertiesType>
  ): void {
    Logger.log(
      `%c CCA ${this.uid} '${context.property}' property changed: ${JSON.stringify(context.previousValue)} ====> ${JSON.stringify(context.value)}`,
      'background: #222; color: #bada55',
    );
  }

  disconnected(element: Element): void {
    Logger.log(`%c CCA ${this.uid} disconnectd`, 'background: #222; color: #bada55');
  }
}
